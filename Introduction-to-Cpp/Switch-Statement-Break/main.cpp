#include <iostream>

int main() {
  int applesFound {0};

  std::cout << "Number of apples found near the UFO: ";
  std::cin >> applesFound;
  
  switch (applesFound) {
    case 1:
      std::cout << "One apple was found!\n";
      break; // Try removing one or more of these breaks!
    case 2: // falling
    case 3: // falling
    case 4: // falling
    case 5: // through
      std::cout << "2-5 apples recovered!\n";
      break;
    default:
      std::cout << applesFound << " apples were present!\n";
  }
}