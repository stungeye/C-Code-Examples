#include "person.h"

// Person constructor.
Person::Person(std::string name, int age) 
      : mName{name}, mAge{age}    // Member variable initializers
{ }

// Defined in the base class only but available to derived class.
void Person::greetings() { 
  std::cout << "Hello, my name is " + mName + ".\n";
}

// Defined in both the base class and the derived class.
std::string Person::debugMessage() { 
  return "name: " + mName + " age: " + std::to_string(mAge);
}
