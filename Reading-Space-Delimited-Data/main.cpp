#include <iostream>
#include <fstream>

int main() {
  std::ifstream inputFile{"input-file.txt"};
  int number;
  
  while (inputFile >> number) { // Stops if we come across bad data.
    std::cout << number << "\n";
  }
}
