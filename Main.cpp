#include <iostream>
#include "Boundry.h"
#include "Blocks.h"
#include "Utility.h"

using namespace std;

int main() {
	Boundry::create_boundry(BOUNDRY_WIDTH, BOUNDRY_HEIGHT);

	srand(time(NULL));
	//Utility::gotoxy(BOUNDRY_WIDTH / 2, 0);
	Blocks::move_block();
	/*char** ar1 = new char* [BLOCK_SIZE];
	char** ar2 = new char* [BLOCK_SIZE];
	int y = 0;
	for (int i = 0; i < BLOCK_SIZE; i++) {
		ar1[i] = new char[BLOCK_SIZE];
		ar2[i] = new char[BLOCK_SIZE];
		for (int j = 0; j < BLOCK_SIZE; j++) {
			int r1 = Utility::get_rand_in_range(0, 2);
			int r2 = 0;
			if (i > 1) {
				r2 = Utility::get_rand_in_range(0, 2);
			}
			if (r1) {
				ar1[i][j] = '*';
			}
			else {
				ar1[i][j] = '\0';
			}
			if (r2) {
				ar2[i][j] = '*';
			}
			else {
				ar2[i][j] = '\0';
			}
		}
	}
	cout << " AR 1 : \n";
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			cout << ar1[i][j] << " ";
		}
		cout << endl;
	}
	cout << " AR 2 : \n";
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			cout << ar2[i][j] << " ";
		}
		cout << endl;
	}
	if (Collision::check_block_collision(ar1, ar2, y)) {
		cout << "Collision : Y : " << y << endl;
	}
	else {
		cout << "No Collision : Y : " << y << endl;
	}*/
	//Blocks::block_movement();
	cin.get();
} 