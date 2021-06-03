#include <iostream>

int main() {
  int ghostQuota = 37;
  int ghostsCaught = 12;

  if (ghostsCaught > ghostQuota) {
    std::cout << "You are done for the day.\n";
  } else {
    auto ghostsRequired = ghostQuota - ghostsCaught;
    std::cout << "You need to find " << ghostsRequired;
    std::cout << " more ghosts. 👻\n";
  }
}