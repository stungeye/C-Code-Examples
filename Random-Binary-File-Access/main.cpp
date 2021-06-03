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

size_t readVectorLength(std::ifstream& in) {
  // Ensure we are at the start of the file.
  in.seekg(0, std::ios::beg); 

  size_t lengthOfVector;
  in.read(reinterpret_cast<char *>(&lengthOfVector), sizeof(size_t));

  return lengthOfVector;
}

Money readNthMoneyRecord(std::ifstream& in, size_t position) {
  // Skip the vector length.
  in.seekg(sizeof(size_t), std::ios::beg); 
  // Seek to the requested record.
  in.seekg(sizeof(Money) * (position - 1), std::ios::cur);  
  Money m;
  // Read the requested record.
  in.read(reinterpret_cast<char *>(&m), sizeof(Money)); 
  
  return m;
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
  size_t numberOfRecords = readVectorLength(inputFile);
  size_t recordToLoad;

  std::cout << "There are " << numberOfRecords << " Money records.\n";
  std::cout << "Which record do you wish to load: ";
  std::cin >> recordToLoad;

  Money money = readNthMoneyRecord(inputFile, recordToLoad);

  std::cout << "$" << money.dollars << "." << money.cents << "\n";
}
