#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void parseSentence(std::string sentence) {
  std::istringstream iss{sentence};
  std::string animal, adjective;
  int number;

  iss >> number >> animal >> adjective;

  std::cout << "There were " << number << " " << adjective << " " << animal << "\n";  
}

int main() {
  constexpr int magicNumber = -999;
  std::ofstream outputFile{"numbers.txt", std::ios_base::binary};
  int number;

  while(true) {
    std::cout << "Number Please: ";
    std::cin >> number;
    if (number == magicNumber) break;
    outputFile.write(reinterpret_cast<char*>(&number), sizeof(number));
  } 

  outputFile.close(); 

  std::ifstream inputFile{"numbers.txt", std::ios_base::binary};   

  while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
      std::cout << number << "\n";
  }

}