#include "Snake.h"

using namespace std;

Snake::Snake(Point initialPosition) : dir(Up) {
  segments.push_back(initialPosition);
}

Snake::~Snake() {}

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
  for (size_t i = segments.size() - 1; i > 0; i--) {
    segments[i] = segments[i - 1];
  }
  Point dirVector = getDirectionVector(dir);
  segments[0] = segments[0] + dirVector;
}

void Snake::turn(Direction d) {
  if (getDirectionVector(d) + getDirectionVector(dir) ==
      Point{0, 0} && getLength() > 1)
    return;
  dir = d;
}