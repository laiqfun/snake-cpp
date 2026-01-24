@echo off
chcp 65001 >nul
echo ========================================
echo         Snake Game Build Script
echo ========================================
echo.

if "%1"=="clean" (
    echo Cleaning build files...
    del /Q *.o snake_game.exe 2>nul
    echo Done!
    exit /b
)

echo Compiling...
g++ -o snake_game src/main.cpp src/Game.cpp src/Snake.cpp src/Food.cpp src/Config.cpp -I include -Wall -std=c++11

if %errorlevel% equ 0 (
    echo.
    echo ========================================
    echo       Compilation Successful!
    echo ========================================
    echo.
    echo Starting game...
    echo.
    snake_game.exe
) else (
    echo.
    echo Compilation failed! Please check errors above.
    exit /b 1
)
