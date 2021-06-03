#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ofstream outputFile{"output.txt"};

  int flightlessBirthCount = 12;
  double portionOfPotion = 56.2;
  std::string confusion = "That wasn't what I meant when I said 'Yes'.\n";

  outputFile << "First line of output.\n";
  outputFile << "Second line of output.\n";
  outputFile << confusion;
  outputFile << flightlessBirthCount << " " << portionOfPotion << "\n";
}