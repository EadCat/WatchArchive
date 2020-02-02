#include <windows.h>
#include "constant.h"

void gotoxy(int x, int y) {
	COORD position;

	position.X = 2*x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
} // 다음 출력 커서 설정 함수

void gotoxy_Wall(int x, int y, int xlim=SpacePadding_x, int ylim=SpacePadding_y ) {
	COORD position;

	position.X = 2 * (x + xlim);
	position.Y = y + ylim;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void gotoxy_Block(int x, int y, int xlim = SpacePadding_x + BoxPadding_x, int ylim = SpacePadding_y + BoxPadding_y) {
	COORD position;

	position.X = 2 * (x + xlim);
	position.Y = y + ylim;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void NoCursor() {
	CONSOLE_CURSOR_INFO hidecur;
	hidecur.bVisible = 0;
	hidecur.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &hidecur);
}

void gotoxy_point(int x, int y) {
	COORD position;

	position.X = 2*x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void gotoxy_title(int x, int y) {
	COORD position;

	position.X = 2 * x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}