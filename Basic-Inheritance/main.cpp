#include <iostream>
#include <string>

class Person {
public: 
  Person(std::string name, int age) // Person constructor
        : mName{name}, mAge{age}    // Member variable initializers
  { }

  // Defined in the base class only but available to derived class.
  void greetings() { 
    std::cout << "Hello, my name is " + mName + ".\n";
  }

  // Defined in both the base class and the derived class.
  std::string debugMessage() { 
    return "name: " + mName + " age: " + std::to_string(mAge);
  }

protected: // Protected members will be accessible to the derived class.
  std::string mName;

private: // Private members will not be accessible to the derived class.
  int mAge;
};

class Student : public Person { // Student inherits from Person
public:
  Student(std::string name, int age, double gpa) // Student constructor
         : Person{name, age}, // Base class constructor call
           mGpa{gpa}          // Member initializer
  { }

  // Redefined function which uses base class version of function.
  std::string debugMessage() { 
    return Person::debugMessage() + " GPA: " + std::to_string(mGpa);
  }

  void writeCode() { // Defined only in the derived class.
    std::cout << mName << " sez: All this coding is making me thirsty!\n";
  }

private: // Derived class private members.
  double mGpa;
};

int main() {
  Person coda{"Condra Forth", 25};
  Student timbre{"Timbre Dalfoor", 43, 3.9};

  // The coda object is-a Person, so we can call Person::greetings().
  coda.greetings();

  // timber is-a Student *and* a Person, so Person::greetings() works too.
  timbre.greetings();

  // The timber oject is-a Student, so we can call Student::writeCode().
  timbre.writeCode();
 
  // We cannot call Student::writeCode() on coda:
  // coda.writeCode(); // Compiler Error: No member named 'writeCode`.

  // Calling .debugMessage() on coda runs Person::debugMessage().
  std::cout << coda.debugMessage() << "\n";

  // Calling .debugMessage() on coda runs Student::debugMessage().
  std::cout << timbre.debugMessage() << "\n";

}