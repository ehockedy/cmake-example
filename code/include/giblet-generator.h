#ifndef INCLUDE_GIBLET_GENERATOR_H_
#define INCLUDE_GIBLET_GENERATOR_H_

#include "giblet-accessory.h"

#include "reader.h"

class GibletGenerator {
public:
  GibletGenerator();
  ~GibletGenerator();
  int GenerateUniqueAccessories(const unsigned int num_accessories);
private:
  GibletAccessory accessory;
};

# endif //INCLUDE_GIBLET_GENERATOR_H_
