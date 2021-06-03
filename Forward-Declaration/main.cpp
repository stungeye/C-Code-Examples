#include <iostream> // for std::cout & std::cin
#include <limits>   // for std::numeric_limits
#include <string>   // for std::string

// Uncomment this line to "forward declare" the fetchInteger function:
// int fetchInteger(std::string prompt);

int main() {
  // Won't compile because fetchInteger hasn't been declared yet.
  int number = fetchInteger("What's your favourite number? ");
  std::cout << number << "\n";
}

int fetchInteger(std::string prompt) {
  do {
    int number;
    std::cout << prompt;

    if (std::cin >> number) {
      return number; 
    }
    
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (true);
}