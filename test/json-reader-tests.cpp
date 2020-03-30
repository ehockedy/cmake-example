#include "../include/reader.h"
#include "../include/io.h"

#include <gtest/gtest.h>


static const char* schema_path = "src/json-reader/giblet-accessories-schema.json";
static const char* test_json = "test/json-test-files/test.json";

class JsonReaderTest : public ::testing::Test {
 protected:
  JsonReaderTest() : jr(test_json, out) {
    out.SetModeSuppressed();

  }
  ~JsonReaderTest() {}

  Outputter out;
  JsonReader jr;
};

TEST_F(JsonReaderTest, JsonLoadsCorrectly) {
  ASSERT_TRUE(jr.JsonLoaded());
}

TEST_F(JsonReaderTest, JsonValidatesCorrectly) {
  ASSERT_TRUE(jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, InvalidNameGiven) {
  jr.SetValue("/entries/0/behaviours/0/name", "INVALID NAME");
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, InvalidBehaviourNameGiven) {
  ASSERT_TRUE(!jr.SetValue("/entries/0/behaviours/0/name", 0)); // THis doesnt seem to be right - seg fault on int
  //ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, BehaviourMultiplierTooBig) {
  jr.SetValue("/entries/0/behaviours/0/multiplier", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, BehaviourMultiplierTooSmall) {
  jr.SetValue("/entries/0/behaviours/0/multiplier", 0);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, StyleNotInListOfOptions) {
  jr.SetValue("/entries/0/styles/0/name", "NOT AN OPTION");
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, StyleMultiplierInvalid) {
  ASSERT_TRUE(!jr.SetValue("/entries/0/styles/0/multiplier", "STRING"));
  //ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, StylemultiplierTooSmall) {
  jr.SetValue("/entries/0/styles/0/multiplier", 0);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, StyleMultiplierTooBig) {
  jr.SetValue("/entries/0/styles/0/multiplier", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, CostInvalid) {
  ASSERT_TRUE(!jr.SetValue("/entries/0/cost", "STRING"));
  //ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, CostTooBig) {
  jr.SetValue("/entries/0/cost", 99999);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, CostTooSmall) {
  jr.SetValue("/entries/0/cost", 0);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, BehaviourNotInListOfOptions) {
  jr.SetValue("/entries/0/behaviours/0/name", "NOT AN OPTION");
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, MinAgeTooLow) {
  jr.SetValue("/entries/0/age_range/min", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, MinAgeTooHigh) {
  jr.SetValue("/entries/0/age_range/min", 100);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, MaxTooLow) {
  jr.SetValue("/entries/0/age_range/max", 10);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

TEST_F(JsonReaderTest, MaxTooHigh) {
  jr.SetValue("/entries/0/age_range/max", 100);
  ASSERT_TRUE(!jr.Validate(schema_path));
}

//TEST_F("Json not valid - out of range age given - min greater than max", "[json-reader]") {
//  JsonReader jr(test_json, out);
//  ASSERT_TRUE(!jr.Validate(schema_path));
//}
