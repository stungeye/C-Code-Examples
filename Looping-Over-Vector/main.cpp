#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector poem{"Mares eat oats", "Goats eat oats"};
  poem.push_back("Little lambs eat ivy");

  for(auto i = 0; i < poem.size(); ++i) {
    std::cout << "Regular For: " << poem[i] << "\n";
  }

  for(auto line : poem) {
    std::cout << "Range For: " << line << "\n";
  }

  poem.resize(20, "");

  for(auto line : poem) {
    std::cout << "With Blanks: " << line << "\n";
  }
}