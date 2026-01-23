#include "Game.h"
#include "Config.h"
#include "Snake.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

Game::Game()
    : map_size(MAP_SIZE), map(MAP_SIZE, vector<char>(MAP_SIZE)),
      snake(startPosition), isPause(false), speed(SPEED_DEFAULT),
      gameOver(false) {
  update();
}

Game::~Game() {}

void Game::restoreMap() {
  for (int i = 0; i < map_size; i++) {
    for (int j = 0; j < map_size; j++) {
      if (i == 0 || i == map_size - 1 || j == 0 || j == map_size - 1) {
        map[i][j] = CHAR_BORDER;
      } else {
        map[i][j] = CHAR_EMPTY;
      }
    }
  }
}

void Game::draw() {
  for (int i = 0; i < map_size; i++) {
    for (int j = 0; j < map_size; j++) {
      _putch(map[i][j]);
    }
    _putch('\n');
  }
}

void Game::addPoints(vector<Point> points, char point_char) {
  for (auto p : points) {
    if (p.x > 0 && p.x < map_size - 1 && p.y > 0 && p.y < map_size - 1)
      map[p.x][p.y] = point_char;
  }
};

void Game::play() {
  isPause = false;
  pastTime = clock();
}

void Game::pause() { isPause = true; }

void Game::snakeMovement() {
  switch (inputKey) {
  case 'w':
    snake.turn(Up);
    break;
  case 's':
    snake.turn(Down);
    break;
  case 'a':
    snake.turn(Left);
    break;
  case 'd':
    snake.turn(Right);
    break;
  }
  snake.move();
}

void Game::gameCheck() {
  Point p = snake.getHead();
  gameOver = !(p.x > 0 && p.x < map_size - 1 && p.y > 0 && p.y < map_size - 1);
}

void Game::update() {
  pastTime = clock();
  while (true) {
    // input
    if (_kbhit()) {
      inputKey = _getch();
      if (inputKey == 'q') {
        cout << "Good bye!" << endl;
        break;
      } else if (inputKey == ' ') {
        isPause = !isPause;
      }
    }
    if (!isPause && float(clock() - pastTime) / CLOCKS_PER_SEC >= 1.0 / speed) {
      // logic
      pastTime = clock();
      snakeMovement();
      gameCheck();
      if (gameOver) {
        cout << "Game Over!" << endl;
        break;
      }
      // render
      restoreMap();
      addPoints(snake.getSegments(), CHAR_SNAKE);

      system("cls");
      draw();
    }
  }
}