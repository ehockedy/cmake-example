#include "rapidjson/document.h"
#include "rapidjson/schema.h"

class RemoteSchemaProvider : public rapidjson::IRemoteSchemaDocumentProvider {
public:
  RemoteSchemaProvider();
  ~RemoteSchemaProvider();
  virtual const rapidjson::SchemaDocument* GetRemoteDocument(const char* uri, rapidjson::SizeType length);
private:
  rapidjson::SchemaDocument* schema_; //TODO make unique ptr
};
