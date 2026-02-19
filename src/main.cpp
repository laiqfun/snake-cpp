#include "Game.h"
#include <iostream>
using namespace std;

int main() {
  Game game;
  bool playAgain = true;
  while (playAgain) {
    game.start();
    cout << "Do you want to play again? (y/n)" << endl;
    char answer;
    cin >> answer;
    playAgain = (answer == 'y');
  }
  return 0;
}