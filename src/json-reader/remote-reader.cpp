#include "remote-reader.h"
#include <fstream>
#include <iostream>
#include "rapidjson/filereadstream.h"
#include "rapidjson/schema.h"

RemoteSchemaProvider::RemoteSchemaProvider() {}

RemoteSchemaProvider::~RemoteSchemaProvider() {
  delete schema_;
}

const rapidjson::SchemaDocument* RemoteSchemaProvider::GetRemoteDocument(const char* uri, rapidjson::SizeType length) {
  //TODO error checking with length param
  std::string extracted_uri = "";
  // Split on "#"
  int i = 0;
  const char char_to_split = '#';
  while (i < length && uri[i] != char_to_split) {
    extracted_uri+=uri[i];
    ++i;
  }

  FILE* fp = fopen(extracted_uri.c_str(), "rb");
  if (fp == NULL) {
    std::cout << "Schema file " << extracted_uri << " failed to open." << std::endl;
    return nullptr;
  }
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  rapidjson::Document schema_file;
  if(schema_file.ParseStream(is).HasParseError()) {
    std::cout << "Schema file " << uri << " is invalid json." << std::endl;
    return nullptr;
  }

  schema_ = new rapidjson::SchemaDocument(schema_file); //TODO change new?
  return schema_;
}
