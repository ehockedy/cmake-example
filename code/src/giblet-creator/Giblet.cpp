#include "GibletPart.h"
#include "json-reader"

GibletPart::GibletPart() {
	id = "0";
	name = "";
}

GibletPart::~GibletPart() {
}

void GibletPart::SetName(std::string new_name) {
	name = new_name;
}

std::string GibletPart::GetID() {
	return id;
}

std::string GibletPart::GetName() {
	return name;
}
