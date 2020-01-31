#include <windows.h>

void gotoxy(int x, int y) {
	COORD position;

	position.X = x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
} // 다음 출력 커서 설정 함수

