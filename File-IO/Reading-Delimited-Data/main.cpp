#include <iostream>
#include <fstream>

int main() {
  std::ifstream inputFile{"input-file.txt"};
  int number;
  
  while (!inputFile.eof()) {
    if (inputFile >> number) {
      std::cout << number << "\n";
    } else {
      inputFile.clear();
      if (char delim; !((inputFile >> delim) && (delim == ','))) {
        std::cerr << "Whoops, bad character: " << delim << "\n";
      }
    }
  }
}