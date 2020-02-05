#include "reader.h"

#include <fstream>
#include <iostream>

JsonReader::JsonReader() {}

JsonReader::~JsonReader() {}
  
bool JsonReader::OpenFile(std::string filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    std::cout << "Json file " << filename << " failed to open." << std::endl;
    return false;
  }
  json_file = nlohmann::json::parse(ifs);
  return true;
}

void JsonReader::PrintJsonEntryWithName(std::string name) {
  std::cout << json_file.dump(2) << std::endl;
}
