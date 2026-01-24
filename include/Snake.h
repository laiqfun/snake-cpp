#ifndef SNAKE_H
#define SNAKE_H

#include "Config.h"
#include <vector>
using namespace std;

class Snake {
private:
  vector<Point> segments;
  Direction dir;

public:
  Snake(Point initialPosition);
  ~Snake();
  void grow();
  void decline();
  void move();
  void turn(Direction d);
  int getLength() const { return segments.size(); };
  Point getHead() const { return segments[0]; };
  vector<Point> getSegments() const { return segments; };
};

#endif
