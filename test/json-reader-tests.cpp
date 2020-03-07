#include "../include/reader.h"

#include <gtest/gtest.h>

const char* schema_path = "src/json-reader/giblet-accessories-schema.json";
const char* test_json = "test/json-test-files/test.json";

TEST(JsonReader, JsonLoadsCorrectly) {
  JsonReader jr(test_json);
  ASSERT_TRUE(jr.JsonLoaded());
}

TEST(JsonReader, JsonValidatesCorrectly) {
  JsonReader jr(test_json);
  ASSERT_TRUE(jr.Validate(schema_path));
}

TEST(JsonReader, InvalidNameGiven) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/name", "INVALID NAME");
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, InvalidBehaviourNameGiven) {
  JsonReader jr(test_json);
  ASSERT_TRUE(!jr.SetValue("/entries/0/behaviours/0/name", 0)); // THis doesnt seem to be right - seg fault on int
  //ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, BehaviourMultiplierTooBig) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/multiplier", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, BehaviourMultiplierTooSmall) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/multiplier", 0);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, StyleNotInListOfOptions) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/name", "NOT AN OPTION");
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, StyleMultiplierInvalid) {
  JsonReader jr(test_json);
  ASSERT_TRUE(!jr.SetValue("/entries/0/styles/0/multiplier", "STRING"));
  //ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, StylemultiplierTooSmall) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/multiplier", 0);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, StyleMultiplierTooBig) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/multiplier", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, CostInvalid) {
  JsonReader jr(test_json);
  ASSERT_TRUE(!jr.SetValue("/entries/0/cost", "STRING"));
  //ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, CostTooBig) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/cost", 99999);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, CostTooSmall) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/cost", 0);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, BehaviourNotInListOfOptions) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/name", "NOT AN OPTION");
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, MinAgeTooLow) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/min", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, MinAgeTooHigh) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/min", 100);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, MaxTooLow) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/max", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST(JsonReader, MaxTooHigh) {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/max", 100);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

//TEST("Json not valid - out of range age given - min greater than max", "[json-reader]") {
//  JsonReader jr(test_json);
//  ASSERT_TRUE(!jr.Validate(schema_path));
//}
