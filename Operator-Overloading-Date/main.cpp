#include <iostream>

class Date {
  static const int daysInMonth[];
  int mYear;
  int mMonth;
  int mDay;

public:
  Date(int y, int m, int d)
    : mYear{y}, mMonth{m}, mDay{d}
  {  }

  bool isLeapYear() const {
    return (mYear % 4 == 0) && ((mYear % 400 == 0) || !(mYear % 100 == 0));
  }

  void debugPrint() const { // Function marked as const.
    std::cout << "Y:" << mYear << " M:" << mMonth << " D:" << mDay << "\n";
  }

  Date operator+(int additionalDays) {
    int leapYearFix = mMonth == 2 && isLeapYear() ? 1 : 0;
    int daysInMonth = Date::daysInMonth[mMonth - 1] + leapYearFix;
    Date newDate{mYear, mMonth, mDay + additionalDays};

    if (newDate.mDay > daysInMonth) {
      newDate.mDay %= daysInMonth;
      newDate.mMonth++;
    }

    if (newDate.mMonth > 12) {
      newDate.mMonth = 1;
      newDate.mYear++;
    }

    return newDate;
  }
};

const int Date::daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
  Date mutableDate{2001, 12, 30};

  mutableDate.debugPrint();

  mutableDate = mutableDate + 5;

  mutableDate.debugPrint();

}