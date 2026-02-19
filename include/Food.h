#ifndef FOOD_H
#define FOOD_H

#include "Config.h"
#include <random>
#include <vector>

class Food {
private:
  std::vector<Point> foodsPositions;
  std::mt19937 rng;

public:
  Food();
  ~Food();
  Point spawnFood(std::vector<Point> points);
  const std::vector<Point> &getPositions() const { return foodsPositions; };
  void eatFood(Point position);
};

#endif