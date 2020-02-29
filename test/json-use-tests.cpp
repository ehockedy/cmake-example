// Tests how to loaded json objects can be used
#define CATCH_CONFIG_MAIN


#include <catch2/catch.hpp>

#include "../include/reader.h"

const char* test_file = "test/json-test-files/test.json";
const char* schema_file = "src/json-reader/giblet-accessories-schema.json";

TEST_CASE("Can load member into new document", "[json-use]") {
  JsonReader jr(test_file);
  CHECK(jr.Validate(schema_file));

  // TODO change with new json maipulation style
  //rapidjson::Document& old_doc = jr.GetJsonFileRef();
  //rapidjson::Document  new_doc;
  //new_doc.SetObject();

  //rapidjson::Value& v = jr//old_doc["entries"][0];

  //rapidjson::Value arr(rapidjson::kArrayType);
  //arr.PushBack(v, old_doc.GetAllocator());

  //new_doc.AddMember("entries", arr, old_doc.GetAllocator());
  

  //REQUIRE(new_doc["entries"].Size() == 1);
  //REQUIRE(old_doc["entries"].Size() == 1);
}

TEST_CASE("Invalid string member requested", "[json-use]") {
  JsonReader jr(test_file);
  REQUIRE(jr.GetString("husehufh") == "");
  //REQUIRE(jr.GetString("/entries/100") == "");
  //REQUIRE(jr.GetString("entries/0") == "");
}
