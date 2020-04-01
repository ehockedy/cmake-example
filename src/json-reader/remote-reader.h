#ifndef SRC_JSON_READER_REMOTE_READER_H_
#define SRC_JSON_READER_REMOTE_READER_H_

#include "rapidjson/document.h"
#include "rapidjson/schema.h"
#include "io.h"

class RemoteSchemaProvider : public rapidjson::IRemoteSchemaDocumentProvider {
public:
  RemoteSchemaProvider(Outputter& out);
  ~RemoteSchemaProvider();
  virtual const rapidjson::SchemaDocument* GetRemoteDocument(const char* uri, rapidjson::SizeType length);
private:
  rapidjson::SchemaDocument* schema_; //TODO make unique ptr
  Outputter& out;
};

#endif  // SRC_JSON_READER_REMOTE_READER_H_
