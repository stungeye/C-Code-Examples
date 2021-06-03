#pragma once // Only include this header file once globally.

#include <iostream>
#include <string>
#include "person.h"

// Student inherits from Person.
class Student : public Person { 
public:
  // Student constructor.
  Student(std::string name, int age, double gpa); 

  // Redefined function which uses base class version of function.
  std::string debugMessage(); 

  // Defined only in the derived class.
  void writeCode(); 

// Derived class private members.
private: 
  double mGpa;
};
