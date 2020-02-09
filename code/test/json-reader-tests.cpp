#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "../include/reader.h"


TEST_CASE("Schema validates json", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(isValid);  
}

TEST_CASE("Json not valid - invalid name", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["name"] = "000";
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}

TEST_CASE("Json not valid - invalid behaviour name", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["behaviours"][0]["name"] = "000";
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}

TEST_CASE("Json not valid - multiplier too big", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["behaviours"][0]["multiplier"] = 10;
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}

TEST_CASE("Json not valid - multiplier too small", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["behaviours"][0]["multiplier"] = 0;
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}

TEST_CASE("Json not valid - invalid style name", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["styles"][0]["name"] = "000";
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}

