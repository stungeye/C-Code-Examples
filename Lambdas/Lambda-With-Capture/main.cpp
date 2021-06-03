#include <iostream>  // std::cout, std::cin
#include <vector>    // std::vector
#include <string>    // std::string
#include <algorithm> // std::count_if

int main()
{
  std::vector<std::string> words{"the", "origin", "of", "consciousness"};

  int longWordLength;

  std::cout << "Long Word Length: ";
  std::cin >> longWordLength;

  auto longWordCount = std::count_if(words.begin(), words.end(),
                                     [longWordLength](const std::string word)
                                     {
                                       return word.length() > longWordLength;
                                     });

  std::cout << "There are " << longWordCount << " words longer than "
            << longWordLength << " characters.\n";
}