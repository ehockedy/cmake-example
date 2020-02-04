#include "Giblet.h"

Giblet::Giblet() {
	id = "0";
	name = "";
}

Giblet::~Giblet() {
}

void Giblet::SetName(std::string new_name) {
	name = new_name;
}

std::string Giblet::GetID() {
	return id;
}

std::string Giblet::GetName() {
	return name;
}
