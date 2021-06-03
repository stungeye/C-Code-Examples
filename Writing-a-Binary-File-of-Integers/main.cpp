#include <iostream>
#include <fstream>

int main() {
  constexpr int magicNumber = -999;
  std::ofstream outputFile{"numbers.txt", std::ios_base::binary};
  int number;

  while(true) {
    std::cout << "Number Please: ";
    std::cin >> number;
    if (number == magicNumber) break;
    outputFile.write(reinterpret_cast<char*>(&number), sizeof(int));
  } 

  outputFile.close(); 

  std::ifstream inputFile{"numbers.txt", std::ios_base::binary};   

  while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
      std::cout << number << "\n";
  }

}