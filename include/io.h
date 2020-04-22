#ifndef INCLUDE_IO_H_ 
#define INCLUDE_IO_H_ 

#include <iostream>
#include <fstream>

enum outputter_mode {
  standard,    // print to terminal
  logger,      // write to log file
  suppressed   // don't do anything
};


/* Custom output class to toggle output on/off for tests
 * Usage should create a single instance at the start, then pass the logger
 * to other classes by reference.
 * The single instance behaviour is not enforced, however.
 * Not that usage of std::endl has ben removed. Use \n instead
 */
class Outputter : public std::ostream {
 public:
  Outputter() {};
  ~Outputter() {};
  void SetModeStandard() {mode = outputter_mode::standard;}
  void SetModeSuppressed() {mode = outputter_mode::suppressed;}
  void SetModeLogger(const char* filename) {
    log_file.open(filename, std::ofstream::out | std::ofstream::trunc); // Overwrite mode
    mode = outputter_mode::logger;
  }
  
  template <class T>
  Outputter& operator<<(const T& value);
  Outputter& operator<<(std::ostream& (*f)(std::ostream&)) = delete; // Stop use of std::endl
 private:
  outputter_mode mode = standard;
  std::ofstream log_file;
};

// These templated definitions must go in .h not .cpp
// This is because if go in cpp, at compile time the type is not resolved and only
// a pattern (the template function) is available
// see: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template <typename T>
Outputter& Outputter::operator<<(const T& value) {
  switch(mode) {
    case outputter_mode::standard:
      std::cout << value;
      break;
    case outputter_mode::logger:
      log_file << value;
    case outputter_mode::suppressed:
    default:
      break;
  }
  return *this;
}


class Inputter {
 public:
  Inputter() {};
  ~Inputter() {};
  std::istream IStream();
// private:
//#ifdef DISABLE_USER_INPUT
//  std::istream istream = std::cin;
//#else
//  std::istream istream;
//#endif
};

#endif // INCLUDE_IO_H_
