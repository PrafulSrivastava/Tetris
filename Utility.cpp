#include "Utility.h"

void Utility::gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int Utility::get_rand_in_range(int from, int to) {
	int temp = rand() % to;
	return max(temp, from);
}