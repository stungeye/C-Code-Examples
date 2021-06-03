#include <iostream>
#include <string>

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

  Money() = default; // Required for line 75 (no-arg initialization).

  // Friend Money + Money operator
  friend Money operator+(const Money& m1, const Money& m2) {
    return Money{m1.mDollars + m2.mDollars, m1.mCents + m2.mCents};
  }

  // Money + int operator (Doesn't need to be a friend.)
  Money operator+(const int cents) const {
    return Money{mDollars, mCents + cents};
  } 

  // Overloaded stream output (friend)
  friend std::ostream& operator<<(std::ostream &out, const Money& money) {
    std::string padding{money.mCents < 10 ? "0" : ""};
    out << "$" << money.mDollars << "." << padding << money.mCents;
    return out;
  }

  // Overloaded stream input (friend)
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
  Money pocketChange{5, 98};
  std::cout << "I've got " << pocketChange << " in my pocket.\n";

  Money foundInFountain{35, 37};
  std::cout << "Swam in public fountian and discovered " << foundInFountain << ".\n";

  Money totalMoney{pocketChange + foundInFountain};
  std::cout << totalMoney << " is my fortune amassed.\n";

  int askInCents = 65;
  std::cout << "Lend me " << askInCents << " cents ";
  std::cout << "and I'll have " << (totalMoney + 65) << "!\n";

  Money userInput; // Required that I add a default non-arg constructor.

  do {
    std::cout << "Enter monetary amount using the format $#.##: ";
    
    if (std::cin >> userInput) {
      break; // Successful read of Money value.
    }

    // No number found so clear the cin error flag:
    std::cin.clear(); 
    // Ignore remaining user input to reset stream for the next try.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (true);

  std::cout << "You entered " << userInput << "\n"; 
}