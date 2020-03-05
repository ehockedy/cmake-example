#ifndef INCLUDE_GIBLET_H_
#define INCLUDE_GIBLET_H_

#include "giblet-accessory.h"
#include <string>
#include <vector>

class Giblet {
 public:
  Giblet();
  ~Giblet();   
  std::string GetName();
  unsigned int GetCost();
  bool AddAccessory(GibletAccessory accessory);
 private:
  std::string name;
  unsigned int cost;
  std::vector<GibletAccessory> accessories;
  const unsigned int max_accessories = 5;
};

# endif //INCLUDE_GIBLET_H_
