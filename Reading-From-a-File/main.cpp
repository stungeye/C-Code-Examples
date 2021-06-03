#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream inputFile{"input.txt"};

  while (inputFile) {
    std::string data;
    inputFile >> data; // Read until space character or end of line.
    std::cout << data << "\n";
  }
}