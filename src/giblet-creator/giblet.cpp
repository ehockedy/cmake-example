
#include "giblet.h"

#include <iostream>
#include <string>
#include <vector>

Giblet::Giblet(){
  name = "";
  cost = 0;
  accessories = {};
}

Giblet::~Giblet(){
}

std::string Giblet::GetName() {
  return name;
}

unsigned int Giblet::GetCost() {
  return cost;
}

bool Giblet::AddAccessory(GibletAccessory accessory) {
  if (accessories.size() == max_accessories) {
    std::cout << "Giblet accessory list full" << std::endl;
    return false;
  }
  accessories.push_back(accessory);
  return true;
}

