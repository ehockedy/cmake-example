#include "../include/reader.h"

#include <gtest/gtest.h>

const char* schema_path = "src/json-reader/giblet-accessories-schema.json";
const char* test_json = "test/json-test-files/test.json";

TEST(JsonReader, JsonLoadsCorrectly) {
  JsonReader jr(test_json);
  ASSERT_TRUE(jr.JsonLoaded());
}

TEST(JsonReader, JsonLoadsCorrectlyNot) {
  JsonReader jr(test_json);
  ASSERT_FALSE(jr.JsonLoaded());
}
