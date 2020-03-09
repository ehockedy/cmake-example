#include "consumer-generator.h"

#include "reader.h"
#include "consumer.h"
#include "giblet.h"

#include <algorithm>
#include <iostream>
#include <vector>

ConsumerGenerator::ConsumerGenerator() {}
ConsumerGenerator::~ConsumerGenerator() {}

int ConsumerGenerator::GenerateUniqueConsumers(const unsigned int num_consumers) {
  JsonReader jr("src/json-reader/consumer_attributes.json");
  if (!jr.JsonLoaded()) return 1;
  //if (!jr.Validate("src/json-reader/giblet-accessories-schema.json", true)) return 1;
  // TODO is there something to validat with?

  unsigned int consumer_count = 0;
  for (consumer_count; consumer_count < num_consumers; ++consumer_count) {
    int size = jr.GetSize("/definitions/behaviours_enum/enum");
    Consumer c;
    c.SetName(jr.GetString("/definitions/consumer_names_enum/enum/%i", rand()%size));
    c.SetBehaviour(jr.GetString("/definitions/behaviours_enum/enum/%i", rand()%size));
    
    std::cout << "Name chosen: " << c.GetName() << std::endl
              << "Behaviour chosen: " << c.GetBehaviour()
              << std::endl << std::endl;
    consumers.push_back(c);
  }
}


std::vector<Consumer>& ConsumerGenerator::GetConsumers() {
  return consumers;
}


bool ConsumerGenerator::CalculateUsageRate(std::vector<Consumer>& consumers, Giblet& giblet) {
  for (auto& c : consumers) {
    std::cout << c.GetName() << ", "
              << c.GetBehaviour() << std::endl;
    for (unsigned a_idx = 0; a_idx < giblet.GetAccessoryCount(); ++a_idx) {
      
    }
    
  }

  return true;
}

