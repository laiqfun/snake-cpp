#ifndef SNAKE_H
#define SNAKE_H

#include "Config.h"
#include <vector>

class Snake {
private:
  std::vector<Point> segments;
  Direction dir;

public:
  Snake(Point initialPosition);
  ~Snake();
  void grow();
  void decline();
  void move();
  void turn(Direction d);
  size_t getLength() const { return segments.size(); };
  Point getHead() const { return segments[0]; };
  const std::vector<Point> &getSegments() const { return segments; };
};

#endif
