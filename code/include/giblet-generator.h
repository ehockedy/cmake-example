#include <vector>

class GibletGenerator {
public:
  GibletGenerator();
  ~GibletGenerator();
  int GenerateUniqueAccessories(unsigned int num_accessories);
  void GenerateUniqueBody(unsigned int num_bodies);
  void GenerateUniqueFeet(unsigned int num_feet);
private:
  std::vector<unsigned int> accessories;
  //Giblet accessory1;
  //std::vector<GibletPart> bodies;
  //std::vector<GibletPart> feet;
};
