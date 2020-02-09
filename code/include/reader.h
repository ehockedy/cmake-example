#ifndef SRC_JSON_READER_READER_H_
#define SRC_JSON_READER_READER_H_

#include <string>
#include "../third_party/rapidjson/document.h"
#include "../third_party/rapidjson/writer.h"
#include "../third_party/rapidjson/stringbuffer.h"

class JsonReader {
public:
  JsonReader();
  ~JsonReader();
  bool OpenFile(const char* filename);
  bool Validate(const char* schema_filename);
  void PrintJsonEntryWithName(std::string name);
  rapidjson::Document* GetJsonFilePtr();
private:
  rapidjson::Document json_file; 
};

#endif  // SRC_JSON_READER_READER_H_
