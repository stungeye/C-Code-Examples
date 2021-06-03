#include <iostream>
#include <string>
#include "person.h"
#include "student.h"

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
