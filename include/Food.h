#include "Config.h"
#include <ctime>
#include <random>
#include <vector>
using namespace std;
class Food {
private:
  vector<Point> foodsPositions;
  mt19937 rng;

public:
  Food();
  ~Food();
  Point spawnFood(vector<Point> points);
  vector<Point> getPositions() const { return foodsPositions; };
  void eatFood(Point position);
};