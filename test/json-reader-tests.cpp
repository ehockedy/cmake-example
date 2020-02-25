#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../include/reader.h"

const char* schema_path = "src/json-reader/giblet-accessories-schema.json";
const char* test_json = "test/json-test-files/test.json";

TEST_CASE("Json file is loaded successfully", "[json-reader]") {
  JsonReader jr(test_json);
  REQUIRE(jr.JsonLoaded());
}

TEST_CASE("Schema validates json", "[json-reader]") {
  JsonReader jr(test_json);
  REQUIRE(jr.Validate(schema_path));
}

TEST_CASE("Json not valid - invalid name", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/name", "INVALID NAME");
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - invalid behaviour name", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/name", 0); // THis doesnt seem to be right - seg fault on int
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - multiplier too big", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/multiplier", 10);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - multiplier too small", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/multiplier", 0);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - invalid style name", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/name", "NOT AN OPTION");
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - invalid style multiplier", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/multiplier", "STRING");
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - style multiplier too small", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/multiplier", 0);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - style multiplier too big", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/multiplier", 10);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - invalid cost", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/cost", "STRING");
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - cost too big", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/cost", 99999);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - cost too small", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/cost", 0);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - behaviour not in list of options", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/behaviours/0/name", "NOT AN OPTION");
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - style not in list of options", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/styles/0/name", "NOT AN OPTION");
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - out of range age given - min too low", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/min", 10);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - out of range age given - min too high", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/min", 100);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - out of range age given - max too low", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/max", 10);
  REQUIRE(!jr.Validate(schema_path));
}

TEST_CASE("Json not valid - out of range age given - max too high", "[json-reader]") {
  JsonReader jr(test_json);
  jr.SetValue("/entries/0/age_range/max", 100);
  REQUIRE(!jr.Validate(schema_path));
}

//TEST_CASE("Json not valid - out of range age given - min greater than max", "[json-reader]") {
//  JsonReader jr(test_json);
//  REQUIRE(!jr.Validate(schema_path));
//}
