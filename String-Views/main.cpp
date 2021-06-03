#include <iostream>
#include <string_view>

void doesStringInclude(std::string_view str, std::string substr) {
  if (str.find(substr) != std::string::npos) {
    std::cout << "'" << str << "' DOES contain '" << substr << "'.\n";
  } else {
    std::cout << "'" << str << "' DOES NOT contain '" << substr << "'.\n";
  }
}

int main() {
  std::string sentence{"A needle in a haystack"};
  doesStringInclude(sentence, "needle");
  doesStringInclude(sentence, "ghost");
}