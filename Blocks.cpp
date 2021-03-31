#include "Blocks.h"

char Blocks::block[BLOCK_SIZE][BLOCK_SIZE] = {};
char Blocks::grid[BOUNDRY_HEIGHT][BOUNDRY_WIDTH] = {};

void Blocks::init_block() {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			block[i][j] = '\0';
		}
	}
}

void Blocks::init_grid() {
	for (int i = 0; i < Y_LIMIT; i++) {
		for (int j = 0; j < X_LIMIT; j++) {
			grid[i][j] = '\0';
		}
	}
}

void Blocks::get_block_figure(int ar[BLOCK_SIZE * BLOCK_SIZE]) {
	int k = 0;
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			block[i][j] = ar[k];
			k++;
		}
	}
}
void Blocks::display_block(int x, int y) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {

			
			if (!grid[y + i][x + j]) {
				if (block[i][j]) {
					Utility::gotoxy(x + j, y + i);
					cout << block[i][j];
				}
				
			}
		}
		cout << endl;
	}
}

/*
1 2 3 
4 5 6
7 8 9

3 6 9
2 5 8
1 4 7

*/

void Blocks::transform_block(int turn) {
	int block_transpose[BLOCK_SIZE][BLOCK_SIZE] = {'\0'};
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			block_transpose[i][j] = block[i][j];
		}
	}
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			if (turn > 0) {
				if (block_transpose[i][j] == BLOCK_TILE)
					block[j][BLOCK_SIZE - i - 1] = block_transpose[i][j];
				else
					block[j][BLOCK_SIZE - i - 1] = '\0';
			}
			else {
				if (block_transpose[i][j] == BLOCK_TILE)
					block[BLOCK_SIZE - j - 1][i] = block_transpose[i][j];
				else
					block[BLOCK_SIZE - j - 1][i] = '\0';
			}
		}
	}
}
/*
	0  1  2  3 	4
	5  6  7  8  9  
	10 11 12 13 14 
	15 16 17 18 19 
	20 21 22 23 24
*/

void Blocks::set_block(int block_id) {
	int ar[BLOCK_SIZE * BLOCK_SIZE] = {0};
	switch (block_id) {
	case 0://Square
		ar[6] = BLOCK_TILE;
		ar[7] = BLOCK_TILE;
		ar[8] = BLOCK_TILE;
		ar[11] = BLOCK_TILE;
		ar[12] = BLOCK_TILE;
		ar[13] = BLOCK_TILE;
		ar[16] = BLOCK_TILE;
		ar[17] = BLOCK_TILE;
		ar[18] = BLOCK_TILE;
		get_block_figure(ar);
		break;
	case 1://|
		ar[2] = BLOCK_TILE;
		ar[7] = BLOCK_TILE;
		ar[12] = BLOCK_TILE;
		ar[17] = BLOCK_TILE;
		ar[22] = BLOCK_TILE;
		get_block_figure(ar);
		break;
	case 2://Z
		ar[1] = BLOCK_TILE;
		ar[6] = BLOCK_TILE;
		ar[11] = BLOCK_TILE;
		ar[12] = BLOCK_TILE;
		ar[13] = BLOCK_TILE;
		ar[18] = BLOCK_TILE;
		ar[23] = BLOCK_TILE;
		get_block_figure(ar);
		break;
	case 3://L
		ar[1] = BLOCK_TILE;
		ar[6] = BLOCK_TILE;
		ar[11] = BLOCK_TILE;
		ar[16] = BLOCK_TILE;
		ar[21] = BLOCK_TILE;
		ar[22] = BLOCK_TILE;
		ar[23] = BLOCK_TILE;
		get_block_figure(ar);
		break;
	}
}


void Blocks::generate_blocks() {
	init_block();
	init_grid();
	int block_id = Utility::get_rand_in_range(0,4);
	set_block(block_id);
}

void Blocks::clear_block(int x, int y) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			Utility::gotoxy(x + j, y + i);
			if (!grid[y+i][x+j]) {
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void Blocks::fill_grid(int x, int y) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			if(!grid[i + y][j + x])
				if(block[i][j])
					grid[i + y][j + x] = block[i][j];
		}
	}
}
void plot_temp(char **temp, int x, int y) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {

			Utility::gotoxy(x + j, y + i);
			if (!temp[i][j])
				cout << "*";
			else
				cout << temp[i][j];
		}
		cout << endl;
	}
}
void Blocks::move_block() {
	int x = X_POS;
	int y = Y_POS;
	generate_blocks();
	bool collided = false;
	while (y < Y_LIMIT - 1) {
		this_thread::sleep_for(chrono::milliseconds(GAME_SPEED));
		if (!_kbhit()) {
			//clear_block(x, y);
			int cnt_y = 0;

			char** temp_block = new char* [BLOCK_SIZE];
			char** temp_grid = new char* [BLOCK_SIZE];
			for (int i = 0; i < BLOCK_SIZE ; i++) {
				temp_block[i] = new char[BLOCK_SIZE];
				temp_grid[i] = new char[BLOCK_SIZE];
				for (int j = 0; j < BLOCK_SIZE ; j++) {
					temp_block[i][j] = block[i][j];
					temp_grid[i][j] = grid[j + y + BLOCK_SIZE][i + x];
				}
			}
			plot_temp(temp_block, MAP_SHIFT_X, 0);
			this_thread::sleep_for(chrono::milliseconds(500));
			plot_temp(temp_grid, MAP_SHIFT_X, MAP_SHIFT_Y);

			if (Collision::check_block_collision(temp_block, temp_grid, cnt_y)) {
				collided = true;
			}



			while (cnt_y-- && y < Y_LIMIT - 1) {
				clear_block(x, y);
				y++;
				display_block(x, y);
				this_thread::sleep_for(chrono::milliseconds(GAME_SPEED));
			}

			for (int i = 0; i < BLOCK_SIZE; i++) {
				delete[] temp_block[i];
				delete[] temp_grid[i];
			}

			delete[] temp_block;
			delete[] temp_grid;

			temp_block = NULL;
			temp_grid = NULL;
		}
		else {
			char key = _getch();
			switch (key) {
			case KB_PAUSE:
				_getch();
				break;
			case KB_ROTATE_LEFT:
				transform_block(ROTATE_ANTI_CLOCKWISE);
				break;
			case KB_ROTATE_RIGHT:
				transform_block(ROTATE_CLOCKWISE);
				break;
			case KB_LEFT:
				if (x - 1 > 0) {
					clear_block(x, y);
					x -= SHIFT;
					display_block(x, y);
				}
				break;
			case KB_RIGHT:
				if (x + 1 < X_LIMIT) {
					clear_block(x, y);
					x += SHIFT;
					display_block(x, y);
				}
				break;

			}
		}

		if (y == Y_LIMIT - 1 || collided) {
			fill_grid(x, y);
			//plot_grid();
			generate_blocks();
			y = 0;
			collided = false;
		}
	}
}

void Blocks::plot_grid() {
	for (int i = 0; i < BOUNDRY_HEIGHT; i++) {
		for (int j = 0; j < BOUNDRY_WIDTH; j++) {

			Utility::gotoxy(MAP_SHIFT_X + j, i);
			cout << grid[i][j];
		}
		cout << endl;
	}
}