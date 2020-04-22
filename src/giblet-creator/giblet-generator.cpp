#include "giblet-generator.h"

#include "giblet-accessory.h"
#include "reader.h"
#include "io.h"

#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>

GibletGenerator::GibletGenerator(Outputter& o, Inputter& i) :
  out(o), in(i) {
  srand(time(0)); 
}

GibletGenerator::~GibletGenerator() {

}

// TODO accept number to choose argument
// TODO pass in custom inputter/outputter module?
int GibletGenerator::GenerateUniqueAccessories(const unsigned int num_accessories) {
  JsonReader jr("src/json-reader/giblet-parts.json", out);
  if (!jr.JsonLoaded()) return 1;
  if (!jr.Validate("src/json-reader/giblet-accessories-schema.json")) return 1;

  unsigned int total_num_accessories = jr.GetSize("/entries");
  if (total_num_accessories < num_accessories) {
    out << "requested too many accessories\n";
    return 1;
  }

  std::vector<int> accessories;
  while (accessories.size() < num_accessories) {
    unsigned int unique_accessory_idx = rand() % total_num_accessories;
    if (std::find(accessories.begin(), accessories.end(),
                  unique_accessory_idx) == accessories.end()) {
      out << "Accessory " << accessories.size() + 1 << ":\n"
                << "Name: " 
                << jr.GetString("/entries/%i/name", unique_accessory_idx) 
                << "\n"
                << "Cost: "
                << jr.GetInt("/entries/%i/cost", unique_accessory_idx)
                << "\n\n";
      accessories.push_back(unique_accessory_idx);
    }
  }

  int accessory_idx = 0;
  while (accessory_idx == 0) {
    out << "Pick an accessory: ";
    std::cin >> accessory_idx;
    if (accessory_idx < 1 || accessory_idx > accessories.size()) {
      out << "Invalid accessory chosen, pick again\n";
      accessory_idx = 0;
    }
  }
  GibletAccessory accessory(jr.GetObjectPtr("/entries/%i", accessory_idx-1)); 

  out << "Name set for chosen accessory " << accessory.GetName() << "\n";

  giblet.AddAccessory(accessory);

  return 0;
}

Giblet& GibletGenerator::GetGiblet() {
  return giblet;
}


