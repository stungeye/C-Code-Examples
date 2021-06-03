#include <iostream>
#include <cmath>

int main() {
  // Reading in an integer. 
  int ducks;
  std::cout << "How many ducks do you see: ";
  std::cin >> ducks;
  std::cout << "There are " << ducks << " ducks.\n";
  // Reading in a double.
  double temperature;
  std::cout << "What is the temperature: ";
  std::cin >> temperature;
  std::cout << "The temperature is " << temperature << ".\n";
}