#ifndef CONFIG_H
#define CONFIG_H

#include <ctime>

const int MAP_SIZE = 11;

enum Direction { Up, Down, Left, Right };

struct Point {
  int x, y;
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}

  Point operator+(const Point &p) const { return {x + p.x, y + p.y}; }
  bool operator==(const Point &p) const { return p.x == x && p.y == y; }
};

const Point startPosition = {MAP_SIZE / 2, MAP_SIZE / 2};

const char CHAR_BORDER = '#';
const char CHAR_EMPTY = ' ';
const char CHAR_SNAKE = 'O';
const char CHAR_FOOD = '*';

const float SPEED_DEFAULT = 2;

Point getDirectonVector(Direction dir);

#endif
