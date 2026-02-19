#include "Config.h"

Point getDirectionVector(Direction dir) {
  switch (dir) {
  case Up:
    return Point{-1, 0};
  case Down:
    return Point{1, 0};
  case Left:
    return Point{0, -1};
  case Right:
    return Point{0, 1};
  }
  return Point{0,0};
};