#ifndef SRC_JSON_READER_READER_H_
#define SRC_JSON_READER_READER_H_

#include <string>
#include "../third_party/rapidjson/document.h"
#include "../third_party/rapidjson/writer.h"
#include "../third_party/rapidjson/stringbuffer.h"
#include "io.h"

class JsonReader {
 public:
  JsonReader(const char*, Outputter& out);
  ~JsonReader();
  
  bool JsonLoaded();
  bool Validate(const char* schema_filename, bool print_error=false);
  
  bool SetValue(const char* key, const char* val);
  bool SetValue(const char* key, const int val);
  
  std::string GetString(const char* key, ...);
  int GetInt(const char* key, ...);
  unsigned int GetSize(const char* key, ...);
  rapidjson::Value* GetObjectPtr(const char* key, ...);

 private:
  Outputter& out;
  std::string GenerateQueryString(const char* key, va_list vars);
  rapidjson::Document json_file; 
};

#endif  // SRC_JSON_READER_READER_H_
