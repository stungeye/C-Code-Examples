#include <iostream>  // For std::cout
#include <algorithm> // For std::copy
#include <array>     // For std::array

int main() {
  // Two C-Style Arrays (Length: 4, Type: int) 
  double original[4]{2,4,6,8};
  double duplicate[4];

  duplicate = original; 

  // Manual copy from original to duplicate array:
  std::copy(std::begin(original), 
            std::end(original), 
            std::begin(duplicate));

  // Must use a separate function to get array length:
  std::cout << "Length of array: " << std::size(duplicate) << "\n";

  // Change position three of the original:
  original[3] = 99;

  // Nice! The copy still has 8 in position 3:
  std::cout << "Still 8: " << duplicate[3] << "\n";

  // Two enhanced Standard Arrays (Length:4, Type: int)
  std::array stdOriginal{2,4,6,8};  // Type and length inferred.
  std::array<int,4> stdDuplicate;   // Type and length specified.

  // Copy by assignment. Easy!
  stdDuplicate = stdOriginal; 

  // Standard arrays can be queries for their length:
  std::cout << "Length of array: " << stdDuplicate.size() << "\n";

  // Original and copy are separate instances:
  stdOriginal[3] = 99;
  std::cout << "Still 8: " << stdDuplicate[3] << "\n";
}