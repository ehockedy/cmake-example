#include "consumer-generator.h"

#include "reader.h"
#include "consumer.h"
#include "giblet.h"

#include <algorithm>
#include <iostream>
#include <vector>

ConsumerGenerator::ConsumerGenerator(Outputter& o, Inputter& i) :
  out(o), in(i) {
  srand(time(0));
}

ConsumerGenerator::~ConsumerGenerator() {}

int ConsumerGenerator::GenerateUniqueConsumers(const unsigned int num_consumers) {
  JsonReader jr("src/json-reader/consumer_attributes.json", out);
  if (!jr.JsonLoaded()) return 1;
  //if (!jr.Validate("src/json-reader/giblet-accessories-schema.json", true)) return 1;
  // TODO is there something to validat with?

  unsigned int consumer_count = 0;
  for (consumer_count; consumer_count < num_consumers; ++consumer_count) {
    int size = jr.GetSize("/definitions/behaviours_enum/enum");
    Consumer c;
    std::cout << "Rand: " << rand()%size << std::endl;
    c.SetName(jr.GetString("/definitions/consumer_names_enum/enum/%i", rand()%size));
    c.SetBehaviour(jr.GetString("/definitions/behaviours_enum/enum/%i", rand()%size));
    
    out << "Name chosen: " << c.GetName() << "\n"
              << "Behaviour chosen: " << c.GetBehaviour()
              << "\n\n";
    consumers.push_back(c);
  }
}


std::vector<Consumer>& ConsumerGenerator::GetConsumers() {
  return consumers;
}

// Take the constructed giblet, and calculate how much the consumer likes the giblet
// This is the "usage rate", and detemines how quickly they will use up the giblet
bool ConsumerGenerator::CalculateUsageRate(std::vector<Consumer>& consumers, Giblet& giblet) {
  unsigned int usage_rate = 1;
  for (auto& c : consumers) {
    std::cout << c.GetName() << ", "
              << c.GetBehaviour() << "\n";
    giblet.ResetAccessoryIndex();
    for (unsigned a_idx = 0; a_idx < giblet.GetAccessoryCount(); ++a_idx) {
      GibletAccessory acc = giblet.GetNextAccessory();
      
      for (unsigned att_idx = 0; att_idx < acc.GetNumBehaviours(); ++att_idx) { //TODO while(GetNextBehaviour(<ref to local var>))
        attribute att = acc.GetNextBehaviour();
        std::cout << "Giblet behaviour name: " << att.name << "\n" 
                  << "Consumer behaviour name: " << c.GetBehaviour() << "\n";
        if (att.name == c.GetBehaviour()) {
          usage_rate *= att.multiplier;
        }
      }
    }
    std::cout << "Usage rate: " << usage_rate << std::endl; 
  }

  return true;
}

