#include <array>     // std::array
#include <algorithm> // std::adjacent_find
#include <iostream>  // std::cout

int main()
{
  std::array months{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  // Find the first two consecutive months that start with the same letter.
  auto sameLetter{
      std::adjacent_find(months.begin(), months.end(),
                         [](const auto &a, const auto &b)
                         { return (a[0] == b[0]); })};

  // If no pair is found, sameLetter will point to .end()
  if (sameLetter != months.end())
  {
    std::cout << *sameLetter << " and " << *std::next(sameLetter)
              << " start with the same letter.\n";
  }
}