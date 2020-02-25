#include "reader.h"
#include "remote-reader.h"

#include <fstream>
#include <iostream>
#include "rapidjson/filereadstream.h"
#include "rapidjson/schema.h"
#include "rapidjson/pointer.h"

JsonReader::JsonReader(const char* filename) {
  FILE* fp = fopen(filename, "rb");
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  if (fp == NULL) {
    std::cout << "Json file " << filename << " failed to open." << std::endl;
    return;
  }
  if(json_file.ParseStream(is).HasParseError()) {
    std::cout << "Json file " << filename << " is invalid json." << std::endl;
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
    std::cout << "Schema file " << schema_filename << " failed to open." << std::endl;
    return false;
  }
  rapidjson::Document schema_file;
  if(schema_file.ParseStream(is).HasParseError()) {
    std::cout << "Schema file " << schema_filename << " is invalid json." << std::endl;
    return false;
  }
  // Validate
  RemoteSchemaProvider provider;
  rapidjson::SchemaDocument schema(schema_file, 0, 0, &provider);
  rapidjson::SchemaValidator validator(schema);
  if (!json_file.Accept(validator)) {
    // Input json file does not line up with schema.
    if (print_error) {
      rapidjson::StringBuffer sb;
      validator.GetInvalidSchemaPointer().StringifyUriFragment(sb);
      printf("Invalid schema: %s\n", sb.GetString());
      printf("Invalid keyword: %s\n", validator.GetInvalidSchemaKeyword());
      sb.Clear();
      validator.GetInvalidDocumentPointer().StringifyUriFragment(sb);
      printf("Invalid document: %s\n", sb.GetString());
    }
    return false;
  }
  return true;
}

void JsonReader::PrintJsonEntryWithName(std::string name) {
  if (!json_file.HasMember(name.c_str())) {
    std::cout << "No entry with name " << name << std::endl;
  } else {
    for (rapidjson::Value::ConstMemberIterator itr = json_file.MemberBegin();
      itr != json_file.MemberEnd(); ++itr)
    {
      std::cout << itr->name.GetString() << std::endl;
    }
  }
}

rapidjson::Document* JsonReader::GetJsonFilePtr() {
  return &json_file;
}

rapidjson::Document& JsonReader::GetJsonFileRef() {
  return json_file;
}

void JsonReader::PointerTest(const char* pointer_path) {
  std::cout << "EH: " << rapidjson::Pointer(pointer_path).Get(json_file)->GetString() << std::endl;
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


