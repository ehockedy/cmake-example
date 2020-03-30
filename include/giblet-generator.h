#ifndef INCLUDE_GIBLET_GENERATOR_H_
#define INCLUDE_GIBLET_GENERATOR_H_

#include "giblet.h"

#include "reader.h"
#include "io.h"

class GibletGenerator {
public:
  GibletGenerator(Outputter& out, Inputter& in);
  ~GibletGenerator();
  int GenerateUniqueAccessories(const unsigned int num_accessories);
  Giblet& GetGiblet();
private:
  Giblet giblet;
  Outputter& out;
  Inputter& in;
};

# endif //INCLUDE_GIBLET_GENERATOR_H_
