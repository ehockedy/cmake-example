#ifndef INCLUDE_CONSUMER_H_
#define INCLUDE_CONSUMER_H_

#include <string>

class Consumer {
 public:
  Consumer();
  ~Consumer();

  std::string GetName();
  std::string GetStyle();
  std::string GetBehaviour();
  unsigned int GetAge();
  unsigned int GetSalary();

  void SetName(std::string);
  void SetStyle(std::string);
  void SetBehaviour(std::string);
  void SetAge(unsigned int);
  void SetSalary(unsigned int);

 private:
  std::string name;
  std::string style;
  std::string behaviour;
  unsigned int age;
  unsigned int salary;
};

# endif //INCLUDE_CONSUMER_H_
