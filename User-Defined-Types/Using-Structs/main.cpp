#include <iostream>
#include <vector>

struct Point {
  int x;
  int y;
};

int main() {
  Point point{5, 10}; // Initializer list: x = 5 and y = 10

  // Public get access to members:
  std::cout << "x: " << point.x << " y: " << point.y << "\n";

  // Public set access to members:
  point.x++;
  point.y = point.x * 10;

  std::cout << "x: " << point.x << " y: " << point.y << "\n";

  std::vector<Point> polygon;

  std::vector<Point> square{ {0, 0}, {0, 12}, {12, 12}, {12, 0} };

  std::cout << square[2].x << "\n";
}