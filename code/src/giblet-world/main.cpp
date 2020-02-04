#include<iostream>
#include "Giblet.h"
 
int main(int argc, char *argv[]){
   Giblet g = Giblet();
   std::cout << "Welcome to the Giblet(tm) factory" << std::endl;
   std::cout << "Created one Giblet with id: " << g.GetID() << std::endl;
   return 0;
}
