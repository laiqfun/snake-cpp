#include "Food.h"
#include "Config.h"
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

Food::Food() : rng(random_device{}()) {}

Food::~Food() {}

Point Food::spawnFood(vector<Point> points) {
  if (points.empty())
    return {};
  uniform_int_distribution<int> dist(0, points.size() - 1);
  int random_int = dist(rng);
  Point p = points[random_int];
  foodsPositions.push_back(p);
  return p;
};

void Food::eatFood(Point position) {
  foodsPositions.erase(remove_if(foodsPositions.begin(), foodsPositions.end(),
                                 [position](const Point &p) {
                                   return position.x == p.x &&
                                          position.y == p.y;
                                 }),
                       foodsPositions.end());
};
