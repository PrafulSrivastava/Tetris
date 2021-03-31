#include "Boundry.h"
void Boundry::create_boundry(int width, int height) {
	for (int i = 0; i < height; i++) {
		if (i == height - 1) {
			for (int j = 0; j < width; j++) {
				cout << BOUNDRY_TILE;
			}
			cout << endl;
		}
		else {
			for (int j = 0; j < width; j++) {
				if (j == 0 || j == width - 1) {
					cout << BOUNDRY_TILE;
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}