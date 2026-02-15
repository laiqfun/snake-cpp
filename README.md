# snake-cpp

贪吃蛇（C++终端版）

## Build and Run

### Using CMake
```bash
# 创建构建目录
mkdir build
cd build

# 生成构建文件
cmake ..

# 编译
cmake --build .

# 运行（Windows）
./Debug/snake_game.exe  # 或 ./Release/snake_game.exe

# 运行（Linux/macOS）
./snake_game
```

## Config

在 ```include/Config.h``` 中修改：

```cpp
MAP_SIZE = 11; # 地图大小

SPEED_DEFAULT = 2; # 蛇的速度

CHAR_BORDER = '#'; # 表示“墙”的符号
CHAR_EMPTY = ' '; # 表示“空地”的符号
CHAR_SNAKE = 'O'; # 表示“蛇”的符号
CHAR_FOOD = '*'; # 表示“食物”的符号

KEY_MOVE_UP = 'w'; # w 向上
KEY_MOVE_DOWN = 's'; # s 向下
KEY_MOVE_LEFT = 'a'; # a 向左
KEY_MOVE_RIGHT = 'd'; # d 向右
KEY_QUIT = 'q'; # q 退出
KEY_PAUSE = ' '; # 空格 暂停
```