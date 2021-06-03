#include <iostream>
#include <array>

int main() {
  std::array numbers{1,2,3,4,5}; 
  
  // Will this work?
  std::cout << "numbers[99] is " << numbers[99] << "\n";
  numbers[99] = 42;
  std::cout << "numbers[99] is " << numbers[99] << "\n";

  // How about if we go further outside the bounds?
  std::cout << "numbers[9999] is " << numbers[9999] << "\n";
  numbers[999] = 42;
  std::cout << "numbers[9999] is " << numbers[9999] << "\n";
}