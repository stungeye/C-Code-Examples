#include <iostream>  // std::cout
#include <array>     // std::array
#include <algorithm> // std::sort

int main()
{
  std::array numbers{9, 99, 4, 44, 300, 3, 12, 2, 200};
  int numberOfComparisons = 0;

  std::sort(numbers.begin(), numbers.end(),
            // Capture comparisons by reference.
            [&numberOfComparisons](const auto &a, const auto &b)
            {
              ++numberOfComparisons; // Mutate the outer variable.
              return (a < b);        // Change to > for descending sort.
            });

  std::cout << numberOfComparisons << " comparisons required.\n";

  for (auto number : numbers)
  {
    std::cout << number << " ";
  }
}