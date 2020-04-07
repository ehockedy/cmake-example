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


TEST_F(JsonUseTest, TooManyPlaceholdersGiven) {
  ASSERT_THROW(jr.GetString("/entries/%i/behaviours/%i/name/%i", 0, 0), InvalidQueryException); // Name doe not have any properties
}

TEST_F(JsonUseTest, PropertyDoesNotExist) {
  ASSERT_THROW(jr.GetString("/entries/%i/behaviours/%i/ABCDEFG", 0, 0), InvalidQueryException);
}

TEST_F(JsonUseTest, MissingFrontSlash) {
  ASSERT_THROW(jr.GetString("entries/%i/behaviours/%i/name", 0, 0), InvalidQueryException);
}
