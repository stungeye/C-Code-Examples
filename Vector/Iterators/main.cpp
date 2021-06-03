#include <algorithm> // std::max_element, std::sort, std::reverse, std::find
#include <iostream>  // std::cout
#include <vector>    // std::vector

int main()
{
  std::vector temperatures{7, -3, 6, 2, -5, 0, 4};

  std::cout << "The highest temperature is "
            << *std::max_element(temperatures.begin(), temperatures.end())
            << ".\n";

  // Sort the vector in ascending order.
  std::sort(temperatures.begin(), temperatures.end());
  // Reverse the order of the vector.
  std::reverse(temperatures.begin(), temperatures.end());
  // Find an iterator to the number 0.
  auto it{find(temperatures.begin(), temperatures.end(), 0)};
  // it will be .end() if zero wasn't found.
  if (it != temperatures.end())
  {
    // Insert 1 right before 0.
    temperatures.insert(it, 1);
  }

  for (auto temperature : temperatures)
  {
    std::cout << temperature << " ";
  }
}