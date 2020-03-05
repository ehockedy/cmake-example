#ifndef INCLUDE_GIBLET_GENERATOR_H_
#define INCLUDE_GIBLET_GENERATOR_H_

#include "giblet.h"

#include "reader.h"

class GibletGenerator {
public:
  GibletGenerator();
  ~GibletGenerator();
  int GenerateUniqueAccessories(const unsigned int num_accessories);
  Giblet& GetGiblet();
private:
  Giblet giblet;
};

# endif //INCLUDE_GIBLET_GENERATOR_H_
