#include <iostream> // for std::cout & std::cin
#include <limits>   // for std::numeric_limits
#include <string>   // for std::string

// To ensure our forward declaration matches implementation:
#include "userInput.h" 

int fetchInteger(std::string prompt) {
  do {
    int number;
    std::cout << prompt;

    if (std::cin >> number) {
      return number; 
    }
    
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (true);
}
