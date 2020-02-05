#include<iostream>
#include "Giblet.h"
#include "reader.h"
 
int main(int argc, char *argv[]){
  Giblet g = Giblet();
  std::cout << "Welcome to the Giblet(tm) factory" << std::endl;
  std::cout << "Created one Giblet with id: " << g.GetID() << std::endl;

  JsonReader jr = JsonReader();
  if (!jr.OpenFile("/home/edhoc/git_repos/giblet-world/code/src/json-reader/giblet-parts.json")) return 1;  //todo remove abolute path
  jr.PrintJsonEntryWithName("top hat"); //todo make this do something more useful
  return 0;
}
