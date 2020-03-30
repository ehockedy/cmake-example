#include <iostream>
#include <string>
#include "giblet-generator.h"
#include "consumer-generator.h"
#include "io.h"
 
int main(int argc, char *argv[]){
  Outputter out;
  Inputter in;

  out << "Welcome to the Giblet(tm) factory\n";

  // Set up world //TODO put this in a set up call
  ConsumerGenerator cg(out, in);
  cg.GenerateUniqueConsumers(1);

  GibletGenerator gg(out, in);
  gg.GenerateUniqueAccessories(2);

  ConsumerGenerator::CalculateUsageRate(cg.GetConsumers(), gg.GetGiblet());

  return 0;
}
