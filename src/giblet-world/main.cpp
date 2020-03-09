#include <iostream>
#include <string>
#include "giblet-generator.h"
#include "consumer-generator.h"
 
int main(int argc, char *argv[]){
  std::cout << "Welcome to the Giblet(tm) factory" << std::endl;

  // Set up world //TODO put this in a set up call
  ConsumerGenerator cg;
  cg.GenerateUniqueConsumers(1);

  GibletGenerator gg;
  gg.GenerateUniqueAccessories(2);

  ConsumerGenerator::CalculateUsageRate(cg.GetConsumers(), gg.GetGiblet());

  return 0;
}
