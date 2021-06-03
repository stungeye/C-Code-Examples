#include <iostream>
#include <string>

int main() {
  std::string haystack{"I still haven't found what I'm looking for."};

  std::string::size_type position;
  
  position = haystack.find("found"); // Search from start.

  if (position != std::string::npos) {
    std::cout << "'Found' position: " << position << "\n";
  }

  position = haystack.find('I', 1); // Search starting at positon 1.

  if (position != std::string::npos) {
    std::cout << "Second 'I' position: " << position << "\n";
  }
}