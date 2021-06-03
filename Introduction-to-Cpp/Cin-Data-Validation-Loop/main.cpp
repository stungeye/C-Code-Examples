#include <iostream>
#include <limits> // for std::numeric_limits

int main() {
  double number;
  
  do {
    std::cout << "Enter a number: ";
    
    if (std::cin >> number) {
      break; // Leave the loop if we read a number from the stream.
    }
    
    // No number found so clear the cin error flag:
    std::cin.clear(); 
    // Ignore remaining user input to reset stream for the next try.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (true);
}