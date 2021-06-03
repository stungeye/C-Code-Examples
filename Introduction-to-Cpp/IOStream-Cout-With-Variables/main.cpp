#include <iostream>

int main() {
  const double pi {3.1415926};
  int answer {42};
  long double hugeNumber {1.5e300};

  std::cout << pi << "\n";
  std::cout << hugeNumber << "\n";
  std::cout << "The answer is " << answer << ".\n";
}