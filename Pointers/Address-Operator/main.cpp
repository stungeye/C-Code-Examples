#include <iostream> // std::cout
#include <string>   // std::string

int main()
{
  int wholeNumber = 42;
  float decimalNumber = 3.14159;
  std::string name = "Wally Glutton";

  std::cout << "The number " << wholeNumber
            << " is stored at memory address "
            << &wholeNumber << ".\n";
  std::cout << "The number " << decimalNumber
            << " is stored at memory address "
            << &decimalNumber << ".\n";
  std::cout << "The string " << name
            << " is stored at memory address "
            << &name << ".\n";
}