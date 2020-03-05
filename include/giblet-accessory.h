#ifndef INCLUDE_GIBLET_ACCESSORY_H_
#define INCLUDE_GIBLET_ACCESSORY_H_

#include <string>
#include "../third_party/rapidjson/document.h"

class GibletAccessory {  // TODO inheret from giblet part
 public:
  GibletAccessory();
  GibletAccessory(rapidjson::Document* object);
  ~GibletAccessory();
  void SetName(std::string name);
  std::string GetName();
  std::string GetID();
 private:
  std::string id;
  std::string name;
};

#endif  // INCLUDE_GIBLET_ACCESSORY_H_
