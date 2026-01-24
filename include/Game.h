#ifndef GAME_H
#define GAME_H

#include "Config.h"
#include "Food.h"
#include "Snake.h"
#include <ctime>
#include <vector>
using namespace std;

class Game {
private:
  int map_size;
  vector<vector<char>> map;
  Snake snake;
  Food food;
  void restoreMap();
  void draw();
  void addPoints(vector<Point> points, char point_char);
  void makeFood();
  bool isPause;
  clock_t pastTime;

  char inputKey;
  void snakeMovement();

  float speed;

  bool gameOver;
  void gameCheck();

  void play();
  void pause();
  void update();

public:
  Game();
  ~Game();
};

#endif
