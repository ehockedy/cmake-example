// Tests how to loaded json objects can be used
#define CATCH_CONFIG_MAIN


#include <catch2/catch.hpp>

#include "../include/reader.h"

TEST_CASE("Can load member into new document", "[json-use]") {
  JsonReader jr;
  jr.OpenFile("test/json-test-files/test.json");
  bool isValid = jr.Validate("src/json-reader/giblet_accessories_schema.json");
  CHECK(isValid);

  rapidjson::Document& old_doc = jr.GetJsonFileRef();
  rapidjson::Document  new_doc;
  new_doc.SetObject();

  rapidjson::Value& v = old_doc["entries"][0];

  rapidjson::Value arr(rapidjson::kArrayType);
  arr.PushBack(v, old_doc.GetAllocator());

  new_doc.AddMember("entries", arr, old_doc.GetAllocator());
  

  REQUIRE(new_doc["entries"].Size() == 1);
  REQUIRE(old_doc["entries"].Size() == 1);
}
