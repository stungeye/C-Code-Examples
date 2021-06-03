#include <iostream>

class Widget {
  public:
    Widget() {
      mId = ++sWidgetsMade;
    }

    static int numberOfWidgetsMade() {
      return sWidgetsMade;
    }

    int id() {
      return mId;
    }

  private:
  static int sWidgetsMade;
  int mId;
};

// Non-const static members must be initialized outside the class.
int Widget::sWidgetsMade{0}; 

int main() {
  std::cout << "Current number of Widgets: " << Widget::numberOfWidgetsMade() << "\n";
  Widget A;
  Widget B;
  std::cout << "Current number of Widgets: " << Widget::numberOfWidgetsMade() << "\n";
  std::cout << "The id of widget A: " << A.id() << "\n";
  std::cout << "The id of widget B: " << B.id() << "\n";
}