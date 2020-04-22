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

// To prevent requesting with an invalid index, only allow cycling through them
// rReturns the accessory that is at the index value of idx_
GibletAccessory Giblet::GetNextAccessory() {
  GibletAccessory& acc = accessories[idx_];
  idx_ = (idx_ + 1) % accessories.size();
  return acc;
}

unsigned int Giblet::GetAccessoryIndex() {
  return idx_;
}

void Giblet::AdvanceAccessoryIndex() {
  ++idx_;
}

void Giblet::ResetAccessoryIndex() {
  idx_ = 0;
}
