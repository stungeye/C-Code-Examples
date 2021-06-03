#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>

class Money{
  static constexpr int centsPerDollar{100};
  int mDollars{0};
  int mCents{0};

  // Ensure that we never have more than 99 cents. 
  void rollCentsIntoDollars() {
    int additionalDollars = mCents / Money::centsPerDollar;
    mDollars += additionalDollars;
    mCents %= Money::centsPerDollar;
  }

public:
  Money(int dollars, int cents) 
    : mDollars{dollars}, mCents{cents}
  { 
    rollCentsIntoDollars();
  }

  Money() = default; // Required for line 58 (no-arg initialization).

  // Overloaded stream output (friend)
  friend std::ostream& operator<<(std::ostream &out, const Money& money) {
    std::string padding{money.mCents < 10 ? "0" : ""};
    out << "$" << money.mDollars << "." << padding << money.mCents;
    return out;
  }

  // Overloaded stream input (friend). Note the out vars.
  friend std::istream& operator>>(std::istream &in, Money& money) {
    int dollars, cents;
    char dollarSign, dot;

    // Parses input in the form: $m.n (where m and n are integers)
    in >> dollarSign >> dollars >> dot >> cents;

    if ((dollarSign != '$') || (dot != '.')) {
      in.clear(std::ios_base::failbit); // Mark input as failed.
    } else {
      money = Money{dollars, cents};
    }

    return in;
  }
};

int main() {
  std::ifstream inputFile{"input-file.txt"};

  // Manually "babysit" the import:
  while (!inputFile.eof()) {
    Money money;
    inputFile >> money;

    if (!inputFile.fail()) {
      std::cout << money << "\n";
    } else {
      std::cerr << "Read bad money value.\n";
      break;
    }
  } 

  // Clear the fail bit if above import read bad value.
  inputFile.clear();
  // Reset the file read pointer to the beginning of file.
  inputFile.seekg(0, std::ios::beg);

  // Read in all money at once using iterator:
  std::vector<Money> bank{
    std::istream_iterator<Money>{inputFile}, {}
  };

  for(Money money : bank) {
    std::cout << money << "\n";
  }
}