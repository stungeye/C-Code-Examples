#pragma once // Only include this header file once globally.

#include <iostream>
#include <string>

// Define our base class Person.
class Person {
public: 
  // Person constructor.
  Person(std::string name, int age); 

  // Defined in the base class only but available to derived class.
  void greetings();

  // Defined in both the base class and the derived class.
  std::string debugMessage();

// Protected members will be accessible to the derived class.
protected: 
  std::string mName;
  
// Private members will not be accessible to the derived class.
private: 
  int mAge;
};
