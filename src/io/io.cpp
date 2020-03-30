#include "io.h"

#include <iostream>

// Use to process std::endl
// Commented out because currently delete this operator specialisation
//Outputter& Outputter::operator<<(std::ostream& (*f)(std::ostream&)) {
//  return *this; 
//}


/**
OutputterMode Outputter::CheckMode() {
  return mode;
}

void Outputter::SetStandardMode() {
  mode = OutputterMode::standard;
}

void Outputter::SetTestMode() {
  mode = OutputterMode::test;
}
*/
//std::ostream Outputter::OStream() {
//  return std::cout;
//}
