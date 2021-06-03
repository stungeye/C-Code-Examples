#include <iostream>

int main() {
  int number;
  std::cout << "Please enter a whole number: ";
  std::cin >> number;
  
  std::cout << "The number " << number << " is ";
  if (number % 2 == 0) {
    std::cout << "even.\n";
  } else {
    std::cout << "odd.\n";
  }
}