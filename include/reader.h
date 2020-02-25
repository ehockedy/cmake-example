#ifndef SRC_JSON_READER_READER_H_
#define SRC_JSON_READER_READER_H_

#include <string>
#include "../third_party/rapidjson/document.h"
#include "../third_party/rapidjson/writer.h"
#include "../third_party/rapidjson/stringbuffer.h"

class JsonReader {
public:
  JsonReader(const char*);
  ~JsonReader();
  bool JsonLoaded();
  bool Validate(const char* schema_filename, bool print_error=false);
  void PrintJsonEntryWithName(std::string name);
  rapidjson::Document* GetJsonFilePtr();
  rapidjson::Document& GetJsonFileRef();
  void PointerTest(const char* pointer_path);
  bool SetValue(const char* key, const char* val);
  bool SetValue(const char* key, const int val);
  	
private:
  rapidjson::Document json_file; 
};

#endif  // SRC_JSON_READER_READER_H_
