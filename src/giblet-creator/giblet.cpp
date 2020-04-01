#include "giblet.h"

#include <iostream>
#include <string>
#include <vector>

Giblet::Giblet(){
  accessories = {};
}

Giblet::~Giblet(){
}

bool Giblet::AddAccessory(GibletAccessory accessory) {
  if (accessories.size() >= max_accessories) {
    return false;
  }
  accessories.push_back(accessory);
  return true; // Index of accessory just aded
}

unsigned int Giblet::GetAccessoryCount() {
  return accessories.size();
}

