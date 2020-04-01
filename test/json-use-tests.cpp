// Tests how to loaded json objects can be used

#include <gtest/gtest.h>
#include "../include/reader.h"
#include "../include/io.h"
#include "../src/json-reader/remote-reader.h"

const char* test_json = "test/json-test-files/test.json";
const char* schema_file = "src/json-reader/giblet-accessories-schema.json";
class JsonUseTest : public ::testing::Test {
 protected:
  JsonUseTest() : jr(test_json, out) {
    out.SetModeSuppressed();
  }
  ~JsonUseTest() {}

  Outputter out;
  JsonReader jr;
};

class JsonRemoteReaderUseTest : public ::testing::Test {
 protected:
  JsonRemoteReaderUseTest() : rsp(out) {
    out.SetModeSuppressed();
  }
  ~JsonRemoteReaderUseTest() {}

  Outputter out;
  RemoteSchemaProvider rsp;
};

TEST_F(JsonUseTest, InvalidStringMemberRequested) {
  ASSERT_TRUE(jr.GetString("husehufh") == "");
}

TEST_F(JsonRemoteReaderUseTest, EmptyStringGiven) {
  out.SetModeLogger("build/test/test_results/JsonRemoteReaderUseTestEmptyStringGiven.txt"); //TODO set logger path better
  const rapidjson::SchemaDocument* sd = rsp.GetRemoteDocument("", 0);
  ASSERT_TRUE(sd == NULL);  
}
