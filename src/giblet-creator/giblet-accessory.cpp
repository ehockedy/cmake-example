#include "giblet-accessory.h"

/**
 * This object only needs to store the name and the cost
 * Once the consumers are created, can find this object in the 
 * json using name as unnique identifier and retrieve the behavious
 * and styles then to calculate the overall usage rate which is
 * stores in the consumer object. 
 */ 

GibletAccessory::GibletAccessory() {
  name = "";
}

GibletAccessory::~GibletAccessory() {
}

void GibletAccessory::SetName(std::string new_name) {
  name = new_name;
}

std::string GibletAccessory::GetName() {
  return name;
}
