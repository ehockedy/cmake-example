#include<iostream>
#include "giblet-generator.h"
//#include "reader.h"
 
int main(int argc, char *argv[]){
  //Giblet g = Giblet();
  //std::cout << "Welcome to the Giblet(tm) factory" << std::endl;
  //std::cout << "Created one Giblet with id: " << g.GetID() << std::endl;
  GibletGenerator gg = GibletGenerator();
  gg.GenerateUniqueAccessories(2);
  //JsonReader jr;
  //if (!jr.OpenFile("src/json-reader/giblet-parts.json")) return 1;
  //if (!jr.Validate("src/json-reader/giblet_accessories_schema.json", true)) return 1;
  //jr.PrintJsonEntryWithName("entries"); //todo make this do something more useful



  return 0;
}
