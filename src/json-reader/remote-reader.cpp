#include "remote-reader.h"

#include "io.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/schema.h"
#include <fstream>

// Implements the IRemoteSchemaDocuementProvider base class

RemoteSchemaProvider::RemoteSchemaProvider(Outputter& o) : out(o) {}

RemoteSchemaProvider::~RemoteSchemaProvider() {
  delete schema_;
}

/** This tells rapidjson how to deal with paths to other files from a schema
 *  If $ref is used in the schema with #<path> as the parameter then it links internally
 *  Otherwise, the behaviour is undefined and the path is not resolved. This function
 *  describes how to resolve the path given.
 *  @param uri Path given that points to some json schema not in this file
 *  @param length Length of uri passed automatcally by rapidjson
 *  @return Pointer to the schema file opened
 */
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
    out << "ERROR: Schema file " << extracted_uri << " failed to open.\n";
    return nullptr;
  }
  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  rapidjson::Document schema_file;
  if(schema_file.ParseStream(is).HasParseError()) {
    out << "ERROR: Schema file " << uri << " is invalid json.\n";
    return nullptr;
  }

  schema_ = new rapidjson::SchemaDocument(schema_file); //TODO change new?
  return schema_;
}
