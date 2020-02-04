#include <string>

class Giblet {
public:
	Giblet();
	~Giblet();
	void SetName(std::string name);
	std::string GetName();
	std::string GetID();
private:
	std::string id;
	std::string name;
};
