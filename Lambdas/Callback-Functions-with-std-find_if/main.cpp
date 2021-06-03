#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <string>    // std::string
#include <algorithm> // std::count_if

bool wordIsLong(std::string word)
{
  return word.length() >= 8;
}

int main()
{
  std::vector<std::string> words{"the", "origin", "of", "consciousness"};

  auto longWordCount = std::count_if(words.begin(), words.end(), wordIsLong);

  std::cout << "There are " << longWordCount << " long words.\n";
}