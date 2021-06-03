#include <iostream>
#include "userInput.h"

int main() {
  // fetchInteger is now defined inside the userInput namespace.
  int number = userInput::fetchInteger("Favourite number? ");
  std::cout << number << "\n";
}