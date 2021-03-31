#pragma once
#include "Globals.h"

using namespace std;

class Collision {
public:
	static bool check_for_vertical_collision(char* ar1, char* ar2);
	static bool check_for_horizontal_collision(char ar1[BLOCK_SIZE], char ar2[BLOCK_SIZE]);
	static bool check_block_collision(char **ar1, char **ar2, int &y);
};