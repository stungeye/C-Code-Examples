#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream inputFile{"input.txt"};

  while (inputFile) {
    std::string data;
    std::getline(inputFile, data);
    std::cout << data << "\n";
  }
}