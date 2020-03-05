#include "consumer.h"

#include <string>
#include <vector>

Consumer::Consumer() {}

Consumer::~Consumer() {}

std::string Consumer::GetName() {
  return name;
}

std::string Consumer::GetStyle() {
  return style;
}

std::string Consumer::GetBehaviour() {
  return behaviour;
}

unsigned int Consumer::GetAge() {
  return age;
}

unsigned int Consumer::GetSalary() {
  return salary;
}

void Consumer::SetName(std::string name) {
  this->name = name;
}

void Consumer::SetStyle(std::string style) {
  this->style = style;
}

void Consumer::SetBehaviour(std::string behaviour) {
  this->behaviour = behaviour;
}

void Consumer::SetAge(unsigned int age) {
  this->age = age;
}

void Consumer::SetSalary(unsigned int salary) {
  this->salary = salary;
}
