#include <iostream>

class Date {
  int mYear;
  int mMonth;
  int mDay;

public:
  Date(int y, int m, int d)
    : mYear{y}, mMonth{m}, mDay{d}
  {  }

  int year() const { // Trivial Getter. Function marked as const.
    return mYear;
  }

  void year(int y) { // Trivial Setter.
    mYear = y;
  }

  void debugPrint() const { // Function marked as const.
    std::cout << "Y:" << mYear << " M:" << mMonth << " D:" << mDay << "\n";
  }
};

int main() {
  Date mutableDate{2021, 01, 01};
  const Date immutableDate{2021, 12, 31};

  mutableDate.debugPrint();
  immutableDate.debugPrint();

  // Attempt to change member variables via setter:
  mutableDate.year(400); // Okay.
  immutableDate.year(400); // Compiler error.
}