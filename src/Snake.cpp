#include "Snake.h"
#include "Config.h"
#include <vector>
using namespace std;

Snake::Snake(Point initialPosition) { segments.push_back(initialPosition); }

Snake::~Snake() {}

Point Snake::getHead() { return segments[0]; }

vector<Point> Snake::getSegments() { return segments; }

void Snake::grow() {
  if (segments.size() > 0) {
    segments.push_back(segments[segments.size() - 1]);
  }
}

void Snake::decline() {
  if (segments.size() > 0) {
    segments.pop_back();
  }
}

void Snake::move() {
  for (int i = segments.size() - 1; i >= 1; i--) {
    segments[i] = segments[i - 1];
  }
  Point dirVector(0, 0);
  switch (dir) {
  case Up:
    dirVector = Point{-1, 0};
    break;
  case Down:
    dirVector = Point{1, 0};
    break;
  case Left:
    dirVector = Point{0, -1};
    break;
  case Right:
    dirVector = Point{0, 1};
    break;
  }
  segments[0] = segments[0] + dirVector;
}

void Snake::turn(Direction d) { dir = d; }