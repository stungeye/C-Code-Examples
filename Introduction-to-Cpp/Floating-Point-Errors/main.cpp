#include <iostream>
#include <iomanip> // For std::setprecision()

int main() {
  // Floating point comparisons are hard:
  if (0.1 + 0.2 == 3.0) {
    std::cout << "This will never print!\n";
  }

  // Increasing the display precision to see why:
  std::cout << std::setprecision(17) << 0.1 + 0.2 << "\n";

  // For this reason, looping with floats is bug-prone:
  for(double value = -1.0; value <= 1.0; value += 0.2) {
    std::cout << value << std::endl;

    if (value == 0) {
      std::cout << "This will also never print!\n";
    }
  }
}