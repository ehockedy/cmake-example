#include "giblet-generator.h"
#include "reader.h"
#include <iostream>
#include <time.h>
#include <algorithm>

GibletGenerator::GibletGenerator() {
  srand(time(0)); 
}

GibletGenerator::~GibletGenerator() {

}

//  void GenerateUniqueAccessories(unsigned int num_accessories);
int GibletGenerator::GenerateUniqueAccessories(unsigned int num_accessories) {
  JsonReader jr;
  if (!jr.OpenFile("src/json-reader/giblet-parts.json")) return 1;
  if (!jr.Validate("src/json-reader/giblet_accessories_schema.json", true)) return 1;
  //jr.PrintJsonEntryWithName("entries"); //todo make this do something more useful
  //rapidjson::Document dom = jr.GetJsonFileRef();

  unsigned int total_num_accessories = jr.GetJsonFileRef()["entries"].Size();
  if (total_num_accessories < num_accessories) {
    std::cout << "requested too many accessories" << std::endl;
  }

  while (accessories.size() < num_accessories) {
    unsigned int unique_accessory_idx = rand() % total_num_accessories;
    if (std::find(accessories.begin(), accessories.end(),
                  unique_accessory_idx) == accessories.end()) {
      accessories.push_back(unique_accessory_idx);
      std::cout << "Accessory " << accessories.size() << ":" << std::endl;
      std::cout << "Name: ";
      std::cout << jr.GetJsonFileRef()["entries"][unique_accessory_idx]["name"].GetString() 
                << std::endl;
      std::cout << "Cost: "
                << jr.GetJsonFileRef()["entries"][unique_accessory_idx]["cost"].GetInt()
                << std::endl;
      std::cout << std::endl;
    }
  }

  return 0;
}

