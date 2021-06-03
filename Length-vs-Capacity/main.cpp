#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector oddNumbers{1, 3, 5, 7}; // Length is 4. Capacity is 4.
  std::cout << "Size: " << oddNumbers.size() << " Capacity: " << oddNumbers.capacity() << "\n";

  oddNumbers.push_back(9); // Length is 5. Capacity is compiler dependent.
  std::cout << "Size: " << oddNumbers.size() << " Capacity: " << oddNumbers.capacity() << "\n";

  oddNumbers.push_back(11); // Length is 6. Capacity is compiler dependent.
  std::cout << "Size: " << oddNumbers.size() << " Capacity: " << oddNumbers.capacity() << "\n";
  
  oddNumbers.pop_back(); // Length is 5. Capacity is compiler dependent.
  std::cout << "Size: " << oddNumbers.size() << " Capacity: " << oddNumbers.capacity() << "\n";
}