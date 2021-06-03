#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Our POD:
struct Money {
  int dollars;
  int cents;
};

void writeVectorOfMoney(std::vector<Money> bank, std::ofstream& out) {
  size_t lengthOfVector{bank.size()};
  // First write the lenght of the vector:
  out.write(reinterpret_cast<char*>(&lengthOfVector),
            sizeof(lengthOfVector));
  // Then write the entire vector in one go:
  out.write(reinterpret_cast<char*>(&bank[0]),
            sizeof(Money) * lengthOfVector);
}

std::vector<Money> readVectorOfMoney(std::ifstream& in) {
  size_t lengthOfVector;
  // First read back the length of the vector:
  in.read(reinterpret_cast<char *>(&lengthOfVector), sizeof(size_t));

  // Create a vector<Money> of the correct length:
  std::vector<Money> inputVector(lengthOfVector);
  // And then read back the vector of Money:
  in.read(reinterpret_cast<char *>(&inputVector[0]), 
          lengthOfVector * sizeof(Money));

  return inputVector;
}

int main() {
  // Sample vector<Money> to write to a file:
  std::vector bank{Money{5, 25}, Money{100, 00}, Money{0, 0}};
  
  // Write the vector to a binary file.
  std::ofstream outputFile{"data.bin", std::ios_base::binary};
  writeVectorOfMoney(bank, outputFile);
  outputFile.close(); 

  // Read the vector back from the binary file.
  std::ifstream inputFile{"data.bin", std::ios_base::binary};  
  std::vector<Money> inputBank{readVectorOfMoney(inputFile)}; 

  // Output the retrieved dollar amounts;
  for(Money m : inputBank) {
    std::cout << "$" << m.dollars << "." << m.cents << "\n";
  }
}
