#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
  const std::vector<std::string> words{"long", "selection", "longest", "consciousness"};

  const auto longWordCount = std::count_if(
      words.begin(),
      words.end(),
      [](std::string word)
      { return word.length() > 8; });

  std::cout << "There are " << longWordCount << " long words.\n";
}