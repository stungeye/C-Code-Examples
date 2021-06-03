#include <iostream> // For std::cout
#include <array>    // For std::array

int main() {
  std::array fibonacci{1, 1, 2, 3, 5, 8, 13};
  
  // Regular indexed for loop:
  for (auto i = 0; i < fibonacci.size(); ++i) {
    std::cout << fibonacci[i] << "\n";
  }

  // Range based for loop:
  for (auto number : fibonacci) {
    std::cout << number << "\n";
  }
  fibonacci[7] = 999;
}