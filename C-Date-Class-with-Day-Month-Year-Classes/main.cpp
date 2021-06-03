#include <iostream>

class Year {
 public:
  class Invalid {};

  Year(int y)
      : year{y} { 
    if (!isValid()) {
      throw Invalid{};
    }
  }

  int operator()() {
    return year;
  }

protected:
  int year;

  bool isValid() { 
    return (year >= 0);
  }
};

class Day {
public:
  class Invalid {};

  Day(int d)
     : day{d} {
    if (!isValid()) {
      throw Invalid{};
    }
  }

  int operator()() {
    return day;
  }

private:
  int day;
  
  bool isValid() {
    return (day >= 1) && (day <= 31);
  }
};

class Month {
public:
  class Invalid {};
  enum class Name { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

  Month(Name name) 
       : month{static_cast<int>(name) + 1}
  { }

  Month(int m) 
       : month{m} {
    if (!isValid()) {
      throw Invalid{};
    }
  }

  int operator()() {
    return month;
  }

private:
  int month;
  
  bool isValid() {
    return (month >= 1) && (month <= 12);
  }
};

class Date {
public:
  Date(Day d, Month m, Year y) 
    : mDay{d}, mMonth{m}, mYear{y}
  {  }

  Date() = default;

  void debugPrint() {
    std::cout << "D:" << mDay() << " M:" << mMonth() << " Y:" << mYear() << "\n";
  }

private:
  Day mDay{1};
  Month mMonth{Month::Name::jan};
  Year mYear{1};
};

int main() {
   Date birthday{Day{27}, Month{Month::Name::sep}, Year{1977}};
   birthday.debugPrint();

   Date halloween{Day{31}, Month{10}, Year{2021}};
   halloween.debugPrint();

   try {
    Date another{Day{1}, Month{12}, Year{1977}};
    another.debugPrint();
   } catch (const Year::Invalid& e) {
     std::cout << "Invalid Year.\n";
   } catch (const Month::Invalid& e) {
     std::cout << "Invalid Month.\n";
   } catch (const Day::Invalid& e) {
     std::cout << "Invalid Day.\n";
   }
}