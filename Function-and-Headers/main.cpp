#include <iostream>
#include "userInput.h"

int main() {
  int number = fetchInteger("Favourite number? ");
  std::cout << number << "\n";
}