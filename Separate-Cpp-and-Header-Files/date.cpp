#include <iostream>
#include "date.h"

// The implementation of the Date class methods:

Date::Date(int y, int m, int d)
    : year{y}, month{m}, day{d}
{ }

void Date::debugPrint() {
  std::cout << "Y:" << year << " M:" << month << " D:" << day << "\n";
}