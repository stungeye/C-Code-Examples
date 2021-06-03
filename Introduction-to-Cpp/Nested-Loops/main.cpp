#include <iostream>

int main() {
  double number;
  
  do {
    std::cout << "\nEnter a number (0 to end): ";
    std::cin >> number;

    for(int i{0}; i < number; i++) {
      std::cout << (i + 1) << "\n";
    }
  } while (number != 0);
}