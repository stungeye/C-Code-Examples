#include <iostream>
#include <fstream>
#include <string>

void writeString(std::string string, std::ofstream& out) {
  size_t lengthOfString = string.length();
  // First write the length of the string:
  out.write(reinterpret_cast<char*>(&lengthOfString), sizeof(size_t));
  // Then write the entire string in one go:
  out.write(string.c_str(), sizeof(char)*lengthOfString);

}

std::string readString(std::ifstream& in) {
  size_t lengthOfString;
  std::string inputString;

  // First the length of the string:
  in.read(reinterpret_cast<char*>(&lengthOfString), sizeof(size_t));
  // Resize storage for the received string:
  inputString.resize(lengthOfString);
  // Read back the string:
  in.read(&inputString[0], sizeof(char)*lengthOfString);
  
  return inputString;
}

int main() {
  std::ofstream outputFile{"data.bin", std::ios_base::binary};
  std::string identifier;

  // Write two strings to our binary file.
  std::cout << "Please provide a text identifier: ";
  getline(std::cin, identifier); 
  writeString(identifier, outputFile);
  writeString("This is a hardcoded string.", outputFile);
  outputFile.close(); 

  // Read two strings from our binary file.
  std::ifstream inputFile{"data.bin", std::ios_base::binary};   
  std::cout << readString(inputFile) << "\n"; 
  std::cout << readString(inputFile) << "\n"; 
}
