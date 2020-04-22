#ifndef INCLUDE_GIBLET_ACCESSORY_H_
#define INCLUDE_GIBLET_ACCESSORY_H_

#include <string>
#include <vector>
#include "../third_party/rapidjson/document.h"

struct attribute {
  std::string name;
  int multiplier;
};

struct range {
  int min;
  int max;
  int multiplier;
};

class GibletAccessory {  // TODO inheret from giblet part
 public:
  GibletAccessory();
  GibletAccessory(rapidjson::Value* object);
  ~GibletAccessory();
  void SetName(std::string name);
  std::string GetName();
  std::string GetID();
  attribute GetNextBehaviour();
  unsigned int GetNumBehaviours() {return behaviours.size();}
  
 private:
  std::string name;
  unsigned int cost;
  std::vector<attribute> behaviours;
  std::vector<attribute> styles;
  range age_range;
  unsigned int idx_;
};

#endif  // INCLUDE_GIBLET_ACCESSORY_H_
