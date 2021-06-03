#include <iostream>
#include <string>

int main() {
  std::string adminUser{"administrator"};
  std::string userPrompt{};
  std::cout << "Username: ";
  std::cin >> userPrompt;

  if (userPrompt == adminUser) {
    std::cout << "Your wish is my command.\n";
  } else {
    std::cout << "Sorry, access denied!\n";
  }
}