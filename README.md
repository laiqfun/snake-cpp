# snake-cpp
贪吃蛇（C++终端版）

## Build and Run
```bash
# 运行 build.bat脚本
build.bat
```

or

```bash
# 编译生成 snake_game.exe
g++ -o snake_game src/main.cpp src/Game.cpp src/Snake.cpp src/Food.cpp src/Config.cpp -I include -Wall -std=c++11

# 运行
snake_game.exe
```

## Config
```cpp
MAP_SIZE = 11; # 地图大小

SPEED_DEFAULT = 2; # 蛇的速度

CHAR_BORDER = '#'; # 表示“墙”的符号
CHAR_EMPTY = ' '; # 表示“空地”的符号
CHAR_SNAKE = 'O'; # 表示“蛇”的符号
CHAR_FOOD = '*'; # 表示“食物”的符号

```