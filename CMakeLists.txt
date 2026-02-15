cmake_minimum_required(VERSION 3.10)

# 项目名称
project(SnakeGame VERSION 1.0)

# 使用C++11标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 收集所有源文件
file(GLOB SOURCES 
    "src/*.cpp"
)

# 创建可执行文件
add_executable(snake_game ${SOURCES})

# 添加头文件目录
target_include_directories(snake_game PRIVATE include)
