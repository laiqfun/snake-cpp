#ifndef SNAKE_H
#define SNAKE_H

#include "Config.h"
#include <vector>
using namespace std;

class Snake {
private:
  vector<Point> segments;
  Direction dir = Up;

public:
  Snake(Point initialPosition);
  ~Snake();
  void grow();
  void decline();
  void move();
  void turn(Direction d);
  Point getHead();
  vector<Point> getSegments();
};

#endif
