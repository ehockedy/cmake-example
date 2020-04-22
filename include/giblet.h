#ifndef INCLUDE_GIBLET_H_
#define INCLUDE_GIBLET_H_

#include "giblet-accessory.h"
#include <string>
#include <vector>

class Giblet {
 public:
  Giblet();
  ~Giblet();   
  bool AddAccessory(GibletAccessory accessory);
  unsigned int GetAccessoryCount();
  unsigned int GetAccessoryIndex();
  GibletAccessory GetNextAccessory();
  void AdvanceAccessoryIndex();
  void ResetAccessoryIndex();
 private:
  std::vector<GibletAccessory> accessories;
  const unsigned int max_accessories = 5;
  unsigned int idx_;
};

# endif //INCLUDE_GIBLET_H_
