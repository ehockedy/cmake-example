// Tests how to loaded json objects can be used

#include <gtest/gtest.h>
#include "../include/reader.h"
#include "../include/io.h"
#include "../src/json-reader/remote-reader.h"

const char* test_json = "test/json-test-files/test.json";
const char* schema_file = "src/json-reader/giblet-accessories-schema.json";

class JsonRemoteReaderUseTest : public ::testing::Test {
 protected:
  JsonRemoteReaderUseTest() : rsp(out) {
    out.SetModeSuppressed();
  }
  ~JsonRemoteReaderUseTest() {}

  Outputter out;
  RemoteSchemaProvider rsp;
};

TEST_F(JsonRemoteReaderUseTest, EmptyStringGiven) {
  //out.SetModeLogger("build/test/test_results/JsonRemoteReaderUseTestEmptyStringGiven.txt"); //TODO set logger path better
  ASSERT_TRUE(rsp.GetRemoteDocument("", 0) == NULL);
}


class JsonUseTest : public ::testing::Test {
 protected:
  JsonUseTest() : jr(test_json, out) {
    out.SetModeSuppressed();
  }
  ~JsonUseTest() {}

  Outputter out;
  JsonReader jr;
};

TEST_F(JsonUseTest, InvalidStringMemberRequested) {
  ASSERT_THROW(jr.GetString("husehufh"), InvalidQueryException);
}

TEST_F(JsonUseTest, ReturnsExpectedValue) {
  EXPECT_STREQ(jr.GetString("/entries/%i/behaviours/%i/name", 0, 0).c_str(), "posh");
  EXPECT_EQ(jr.GetInt("/entries/%i/behaviours/%i/multiplier", 0, 0), 2);
  EXPECT_EQ(jr.GetSize("/entries/%i/behaviours", 0, 0), 1);
  EXPECT_TRUE(jr.GetObjectPtr("/entries/%i/behaviours/%i", 0, 0) != nullptr);
}

TEST_F(JsonUseTest, TooManyPlaceholdersGiven) {
  ASSERT_THROW(jr.GetString("/entries/%i/behaviours/%i/name/%i", 0, 0), InvalidQueryException); // Name does not have any properties
  ASSERT_THROW(jr.GetInt("/entries/%i/behaviours/%i/multiplier/%i", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetSize("/entries/%i/behaviours/%i/name/%i", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetObjectPtr("/entries/%i/behaviours/%i/name/%i", 0, 0), InvalidQueryException);
}

TEST_F(JsonUseTest, PropertyDoesNotExist) {
  ASSERT_THROW(jr.GetString("/entries/%i/behaviours/%i/ABCDEFG", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetInt("/entries/%i/behaviours/%i/ABCDEFG", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetSize("/entries/%i/behaviours/%i/ABCDEFG", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetObjectPtr("/entries/%i/behaviours/%i/ABCDEFG", 0, 0), InvalidQueryException);
}

TEST_F(JsonUseTest, MissingFrontSlash) {
  ASSERT_THROW(jr.GetString("entries/%i/behaviours/%i/name", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetInt("entries/%i/behaviours/%i/multiplier", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetSize("entries/%i/behaviours/%i/name", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetObjectPtr("entries/%i/behaviours/%i/name", 0, 0), InvalidQueryException);
}

TEST_F(JsonUseTest, IsNotCorrectType) {
  ASSERT_THROW(jr.GetString("/entries/%i/behaviours/%i/multiplier", 0, 0), InvalidQueryException);
  ASSERT_THROW(jr.GetInt("/entries/%i/behaviours/%i/name", 0, 0), InvalidQueryException);
}

TEST_F(JsonUseTest, CustomExceptionWhat) {
  std::string what_msg = "";
  try {
    jr.GetObjectPtr("/entries/%i/behaviours/%i/name", 0, 0); // Will throw
  } catch (InvalidQueryException& e) {
     what_msg = std::string(e.what());
  }
  ASSERT_GT(what_msg.size(), 0);
}
