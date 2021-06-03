#include <iostream>

int main() {
  short overflowShort = 32767; // Maximum short.
  unsigned int overflowInt= 0; // Minimum unsigned int.
  
  std::cout << "Before Overflow:\n";
  std::cout << overflowShort << "\n"; // 32767
  std::cout << overflowInt << "\n";   // 0

  overflowShort++; // One greater than max short.
  overflowInt--;   // One less than min unsigned int.

  std::cout << "After Overflow:\n";
  std::cout << overflowShort << "\n"; // -32768
  std::cout << overflowInt << "\n";   // 4294967295
}