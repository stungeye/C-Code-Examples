#include <iostream>
#include <string>

class LoudMouth {
  public:
  LoudMouth(std::string n)
    : name{n} {
    std::cout << "  📣  Constructor: " << name << "\n";
  }

  ~LoudMouth() {
    std::cout << "  📣  Destructor: " << name << "\n";
  }

  private:
  std::string name;
};

int main() {
  std::cout << "Program main() begins.\n";
  LoudMouth wally{"Wally"};

  if (1 == 1) { // Useless test to create a nested scope.
    std::cout << "  If scope begins.\n  ";
    LoudMouth daisy{"Daisy"};
    std::cout << "  If scope ends.\n  ";
  }

  std::cout << "Program main() ends.\n";
}