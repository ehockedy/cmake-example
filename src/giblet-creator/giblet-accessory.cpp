#include "giblet-accessory.h"
#include "../third_party/rapidjson/document.h"


/**
 * Object that maps to json object
 */ 

GibletAccessory::GibletAccessory() {
  name = "";
  cost = 0;
  age_range = {0, 0, 0};
}

GibletAccessory::GibletAccessory(rapidjson::Value* object) {
  name = object->FindMember("name")->value.GetString();
  cost = object->FindMember("cost")->value.GetInt();
  for (auto& b : object->FindMember("behaviours")->value.GetArray()) {
    behaviours.push_back( 
      attribute {
        b.FindMember("name")->value.GetString(),
        b.FindMember("multiplier")->value.GetInt()
      });
  }
  for (auto& s : object->FindMember("styles")->value.GetArray()) {
    styles.push_back( 
      attribute {
        s.FindMember("name")->value.GetString(),
        s.FindMember("multiplier")->value.GetInt()
      });
  }
  age_range = range {
                object->FindMember("age_range")->value.FindMember("min")->value.GetInt(),
                object->FindMember("age_range")->value.FindMember("max")->value.GetInt(),
                object->FindMember("age_range")->value.FindMember("multiplier")->value.GetInt()
              };
}

GibletAccessory::~GibletAccessory() {
}

void GibletAccessory::SetName(std::string new_name) {
  name = new_name;
}

std::string GibletAccessory::GetName() {
  return name;
}
