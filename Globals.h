#pragma once
#include <thread>
#include <conio.h>
#include <iostream>
#include "Utility.h"

#define BOUNDRY_TILE '#'
#define BOUNDRY_HEIGHT 15
#define BOUNDRY_WIDTH 30

#define BLOCK_SIZE 5
#define BLOCK_TILE '@'
#define ROTATE_ANTI_CLOCKWISE -1
#define ROTATE_CLOCKWISE 1
#define SHIFT 1
#define MAP_SHIFT_X 40
#define MAP_SHIFT_Y 9

#define X_LIMIT (BOUNDRY_WIDTH - BLOCK_SIZE)
#define X_POS X_LIMIT/2
#define Y_LIMIT BOUNDRY_HEIGHT - BLOCK_SIZE
#define Y_POS 0

#define GAME_SPEED 200

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ROTATE_LEFT 9
#define KB_ROTATE_RIGHT 32
#define KB_PAUSE 13
