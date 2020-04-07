#include "reader.h"
#include "remote-reader.h"
#include "io.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <stdarg.h>
#include <string>
#include "rapidjson/filereadstream.h"
#include "rapidjson/schema.h"
#include "rapidjson/pointer.h"

/**class InvalidQueryException : public std::exception {
 public:
  InvalidQueryException(std::string q) : query(q) {}
  const char* what () const throw () {
    return ("Invalid Json query given: " + query).c_str();
  }
 private:
  std::string query;
};*/

JsonReader::JsonReader(const char* filename, Outputter& o) :
  out(o) {
  FILE* fp = fopen(filename, "rb");
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  if (fp == NULL) {
    out << "Json file " << filename << " failed to open.\n";
    return;
  }
  if(json_file.ParseStream(is).HasParseError()) {
    out << "Json file " << filename << " is invalid json.\n";
    return;
  }
}

JsonReader::~JsonReader() {}

bool JsonReader::JsonLoaded() {
  return !json_file.IsNull();
}

bool JsonReader::Validate(const char* schema_filename, bool print_error) {
  // Load schema file
  FILE* fp = fopen(schema_filename, "rb");
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  if (fp == NULL) {
    out << "Schema file " << schema_filename << " failed to open.\n";
    return false;
  }
  rapidjson::Document schema_file;
  if(schema_file.ParseStream(is).HasParseError()) {
    out << "Schema file " << schema_filename << " is invalid json.\n";
    return false;
  }
  // Validate
  RemoteSchemaProvider provider(out);
  rapidjson::SchemaDocument schema(schema_file, 0, 0, &provider);
  rapidjson::SchemaValidator validator(schema);
  if (!json_file.Accept(validator)) {
    // Input json file does not line up with schema.
    if (print_error) {
      rapidjson::StringBuffer sb;
      validator.GetInvalidSchemaPointer().StringifyUriFragment(sb);
      out << "Invalid schema: " << sb.GetString() << "\n";
      out << "Invalid keyword: " << validator.GetInvalidSchemaKeyword() << "\n";
      sb.Clear();
      validator.GetInvalidDocumentPointer().StringifyUriFragment(sb);
      out << "Invalid document: " << sb.GetString() << "\n";
    }
    return false;
  }
  return true;
}

bool JsonReader::SetValue(const char* key, const char* val) {
  rapidjson::Value* v = rapidjson::Pointer(key).Get(json_file);
  if (!v->IsString()) return false;
  v->SetString(val, 0);  // json_file.GetAllocator());
  return true;
}

bool JsonReader::SetValue(const char* key, const int val) {
  rapidjson::Value* v = rapidjson::Pointer(key).Get(json_file);
  if (!v->IsNumber()) return false;

  v->SetInt(val);
  return true;
}


std::string JsonReader::GenerateQueryString(const char* key, va_list vars) {
  if (key[0] == '\0') {
    out << "Invalid query string - must not be empty\n";
    throw InvalidQueryException(std::string(key));
  }
  if (key[0] != '/') {
    out << "Invalid query string \"" << key << "\" must start with /\n";
    throw InvalidQueryException(std::string(key));
  }
  std::string json_query = "";
  // Split on %x where x indicates the type
  // Currently supported types:
  //  s : string
  //  i : int 
  int i = 0;
  const char char_to_split = '%';  //TODO have escape character option
  while (key[i] != '\0') {  // Until end of char array
    //printf("%c ", key[i]);
    if (key[i] == char_to_split) {
      //printf("   symbol found");
      if (key[i] == '\0') throw InvalidQueryException(std::string(key)); // % without a character after
      ++i;  // Advance to the type character
      switch (key[i]) {  // Decide the type
        case 's':
          json_query += va_arg(vars, char*);
          break;
        case 'i':
          json_query += std::to_string(va_arg(vars, int));
          break;
        default:
          // TODO throw exception
          out << "ERROR: invalid json reader query type given\n";
          json_query += char_to_split;
          json_query += key[i];
          throw InvalidQueryException(json_query); // Throw at the point of the error
      }
    } else { // standard character in the query
      json_query += key[i]; 
    }
    ++i; // Advance to next character in input char array
  }
  return json_query;
}

std::string JsonReader::GetString(const char* key, ...) {
  va_list vars;  // Hold the multiple vars supplied
  va_start(vars, key);
  std::string json_query = GenerateQueryString(key, vars);
  va_end(vars);

  if (json_query[0] != '/') throw InvalidQueryException(std::string(key));
  rapidjson::Value* v = rapidjson::Pointer(json_query.c_str()).Get(json_file);
  if (v == nullptr) throw InvalidQueryException(json_query); // TODO better return value as this could be valid json
  if (!v->IsString()) return ""; // TODO throw exception?
  return v->GetString();
}

int JsonReader::GetInt(const char* key, ...) {
  va_list vars;  // Hold the multiple vars supplied
  va_start(vars, key);
  std::string json_query = GenerateQueryString(key, vars);
  va_end(vars);

  rapidjson::Value* v = rapidjson::Pointer(json_query.c_str()).Get(json_file);
  if (v == nullptr) return -1;
  if (!v->IsNumber()) return -1; // TODO throw exception?
  return v->GetInt();
}

unsigned int JsonReader::GetSize(const char* key, ...) {
  va_list vars;
  va_start(vars, key);
  std::string json_query = GenerateQueryString(key, vars);
  va_end(vars);
  rapidjson::Value* v = rapidjson::Pointer(json_query.c_str()).Get(json_file);
  if (v == nullptr) return 0; // TODO better ret value/error reporting
  return v->Size();
}

rapidjson::Value* JsonReader::GetObjectPtr(const char* key, ...) {
  va_list vars;
  va_start(vars, key);
  std::string json_query = GenerateQueryString(key, vars);
  va_end(vars);
  rapidjson::Value* v = rapidjson::Pointer(json_query.c_str()).Get(json_file);
  if (v == nullptr) out << "NULL pointer\n"; // TODO better ret value/error reporting
  if (!v->IsObject()) out << "NULL object\n"; // TODO better ret value/error reporting
  return v;
}
