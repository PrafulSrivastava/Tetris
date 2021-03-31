#include "Collision.h"

bool Collision::check_for_vertical_collision(char *ar1, char *ar2) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		if(ar2[i]){
			if (ar1[i]) {
				return true;
			}
		}
	}
	return false;
}
bool Collision::check_for_horizontal_collision(char ar1[BLOCK_SIZE], char ar2[BLOCK_SIZE]) {
	for (int i = 0; i < BLOCK_SIZE; i++) {
		if (ar2[i]) {
			if (ar1[i]) {
				return true;
			}
		}
	}
	return false;
}

bool Collision::check_block_collision(char** ar1, char** ar2, int &y) {
	
	int l = 0;
	while (l < BLOCK_SIZE) {
		int k = BLOCK_SIZE - l - 1;
		for (int i = 0; i < l + 1; i++) {
			for (int j = 0; j < BLOCK_SIZE; j++) {
				if (ar1[k][j]) {
					if (ar2[i][j]) {
						//cout << "Collsion in row : " << k << " of block and row : " << i << " of grid" <<" at : (" <<k<<","<<j<<")" << " and : (" << i << "," << j << ")" <<endl;
						return true;
					}
				}
			}
			//cout << "No collsion in row : " << k << " of block and row : " << i << "of grid" << endl;
			k++ ;
		}
		y++;
		l++;
	}
	return false;
}