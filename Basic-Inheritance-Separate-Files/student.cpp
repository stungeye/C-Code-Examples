#include "student.h"

// Student constructor.
Student::Student(std::string name, int age, double gpa) 
        : Person{name, age}, // Base class constructor call
          mGpa{gpa}          // Member initializer
{ }

// Overrides and uses base class version of function.
std::string Student::debugMessage() { 
  return Person::debugMessage() + " GPA: " + std::to_string(mGpa);
}

// Defined only in the derived class.
void Student::writeCode() { 
  std::cout << mName << " sez: All this coding is making me thirsty!\n";
}