#pragma once
#include <windows.h>
#include <time.h>


using namespace std;

class Utility {
public :
	static void gotoxy(int x, int y);
	static int get_rand_in_range(int from, int to);
};