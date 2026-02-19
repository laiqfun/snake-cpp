#include "Game.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Game::Game()
    : map_size(MAP_SIZE), map(MAP_SIZE, vector<char>(MAP_SIZE)),
      snake(startPosition), food(), isPause(false), speed(SPEED_DEFAULT),
      gameOver(false) {
  initMap();
}

Game::~Game() {}

void Game::initMap() {
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

void Game::restoreMap() {
  int border_width = 1;
  for (int i = border_width; i < map_size - border_width; i++) {
    for (int j = border_width; j < map_size - border_width; j++) {
      map[i][j] = CHAR_EMPTY;
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

void Game::addPoints(const vector<Point> &points, char point_char) {
  for (const auto &p : points) {
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
  case KEY_MOVE_UP:
    snake.turn(Up);
    break;
  case KEY_MOVE_DOWN:
    snake.turn(Down);
    break;
  case KEY_MOVE_LEFT:
    snake.turn(Left);
    break;
  case KEY_MOVE_RIGHT:
    snake.turn(Right);
    break;
  }
  snake.move();
}

void Game::makeFood() {
  vector<vector<bool>> unavailableMap(map_size, vector<bool>(map_size));
  vector<Point> availableMap;
  for (int i = 0; i < map_size; i++) {
    unavailableMap[0][i] = 1;
    unavailableMap[map_size - 1][i] = 1;
    unavailableMap[i][0] = 1;
    unavailableMap[i][map_size - 1] = 1;
  }
  for (const auto &p : snake.getSegments()) {
    unavailableMap[p.x][p.y] = 1;
  }
  for (int i = 0; i < map_size; i++) {
    for (int j = 0; j < map_size; j++) {
      if (!unavailableMap[i][j]) {
        availableMap.push_back(Point{i, j});
      }
    }
  }
  food.spawnFood(availableMap);
}

void Game::gameCheck() {
  Point p = snake.getHead();
  gameOver = !(p.x > 0 && p.x < map_size - 1 && p.y > 0 && p.y < map_size - 1);

  const vector<Point> &segments = snake.getSegments();
  for (int i = 1; i < snake.getLength(); i++) {
    if (p == segments[i]) {
      gameOver = true;
      break;
    }
  }

  if (gameOver)
    return;

  const vector<Point> &foods = food.getPositions();
  if (foods.empty()) {
    makeFood();
  } else {
    for (const auto &f : foods) {
      if (p == f) {
        food.eatFood(f);
        snake.grow();

        makeFood();
        break;
      }
    }
  }
}

void Game::update() {
  pastTime = clock();
  while (true) {
    // input
    if (_kbhit()) {
      inputKey = _getch();
      if (inputKey == KEY_QUIT) {
        cout << "Good bye!" << endl;
        break;
      } else if (inputKey == KEY_PAUSE) {
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
      addPoints(food.getPositions(), CHAR_FOOD);

      system("cls");
      draw();
    }
  }
}

void Game::start() {
  system("cls");
  cout << "=== Snake Game ===" << endl;
  cout << "Controls:" << endl;
  cout << "  w/a/s/d - Move" << endl;
  cout << "  Space   - Pause" << endl;
  cout << "  q       - Quit" << endl;
  cout << "\nPress any key to start..." << endl;
  system("pause");
  system("cls");
  update();
}