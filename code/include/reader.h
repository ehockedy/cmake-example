#ifndef SRC_JSON_READER_READER_H_
#define SRC_JSON_READER_READER_H_

#include <string>
#include <../third_party/nlohmann/json.hpp>

class JsonReader {
public:
  JsonReader();
  ~JsonReader();
  bool OpenFile(std::string);
  void PrintJsonEntryWithName(std::string name);
private:
  nlohmann::json json_file; 
};

#endif  // SRC_JSON_READER_READER_H_
