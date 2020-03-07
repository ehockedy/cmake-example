// Tests how to loaded json objects can be used

#include <gtest/gtest.h>
#include "../include/reader.h"

const char* test_file = "test/json-test-files/test.json";
const char* schema_file = "src/json-reader/giblet-accessories-schema.json";

TEST(JsonUse, InvalidStringMemberRequested) {
  JsonReader jr(test_file);
  ASSERT_TRUE(jr.GetString("husehufh") == "");
  //REQUIRE(jr.GetString("/entries/100") == "");
  //REQUIRE(jr.GetString("entries/0") == "");
}
