// Tests how to loaded json objects can be used

#include <gtest/gtest.h>
#include "../include/reader.h"
#include "../include/io.h"

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

TEST_F(JsonUseTest, InvalidStringMemberRequested) {
  ASSERT_TRUE(jr.GetString("husehufh") == "");
  //REQUIRE(jr.GetString("/entries/100") == "");
  //REQUIRE(jr.GetString("entries/0") == "");
}
