#include <windows.h>

void gotoxy(int x, int y) {
	COORD position;

	position.X = x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
} // ���� ��� Ŀ�� ���� �Լ�

