#include<iostream>
#include "giblet-generator.h"
 
int main(int argc, char *argv[]){
  std::cout << "Welcome to the Giblet(tm) factory" << std::endl;

  GibletGenerator gg = GibletGenerator();
  gg.GenerateUniqueAccessories(2);

  return 0;
}
