#include "Config.h"

Point getDirectonVector(Direction dir) {
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
  return dirVector;
};