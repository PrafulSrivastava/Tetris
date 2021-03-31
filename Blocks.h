#pragma once
#include "Globals.h"
#include "Collision.h"

using namespace std;

class Blocks {
public:
	static char block[BLOCK_SIZE][BLOCK_SIZE];
	static char grid[BOUNDRY_HEIGHT][BOUNDRY_WIDTH];

	static void init_grid();
	static void fill_grid(int x, int y);
	static void init_block();
	static void display_block(int x, int y);
	static void transform_block(int turn);
	static void get_block_figure(int ar[BLOCK_SIZE * BLOCK_SIZE]);
	static void set_block(int block_id);
	static void generate_blocks();
	static void clear_block(int x, int y);
	static void plot_grid();
	static void move_block();
};