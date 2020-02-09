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

TEST_CASE("Json not valid - invalid style multiplier", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["styles"][0]["multiplier"] = "2";
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
TEST_CASE("Json not valid - style multiplier too small", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["styles"][0]["multiplier"] = 0;
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
TEST_CASE("Json not valid - style multiplier too big", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["styles"][0]["multiplier"] = 10;
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
TEST_CASE("Json not valid - invalid cost", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["cost"] = "100";
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
TEST_CASE("Json not valid - cost too big", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["cost"] = 99999;
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
TEST_CASE("Json not valid - cost too small", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["cost"] = 0;
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
TEST_CASE("Json not valid - behaviour not in list of options", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["behaviours"][0]["name"] = "NOT AN OPTION";
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
TEST_CASE("Json not valid - style not in list of options", "[json-reader]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  rapidjson::Document* d = jr.GetJsonFilePtr();
  (*d)["entries"][0]["styles"][0]["name"] = "NOT AN OPTION";
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  REQUIRE(!isValid);
}
