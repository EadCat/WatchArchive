#include "constant.h"
#include "block.h"
#include "draw.h"
#include "cursor.h"

#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

int stopper = 2;
int ender = 1;

int main()
{
	block tetra;
	screen tfield;
	CONSOLE_CURSOR_INFO cursorSet;
	int order; // ����Ű ����

	srand(time(NULL)); // ��� ���� ����
	draw_box(tfield.field); // box drawing

	// Ŀ�� ����
	cursorSet.dwSize = 1;
	cursorSet.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorSet);

	while (1) // game start
	{
		tfield.x = WIDTH / 2;
		tfield.y = 0;
		tetra.caller = (rand() % 7) + 1; // { 1, 2, 3, 4, 5, 6, 7 }
		tetra.phase = (rand() % 4 + 1); // { 1, 2, 3, 4 }
		block_maker(tetra.caller, tetra.phase, tfield.x, tfield.y, tfield.field);
		drawing_block(tetra.caller, tetra.phase, tfield.x, tfield.y, 1);
		
		while (ender) // moving phase
		{
			if (_kbhit()) {
				order = _getch();
				if (order == LEFT || order == RIGHT || order == DOWN || order == SPACE) {
					//move
					block_eraser(tetra.caller, tetra.phase, tfield.x, tfield.y, tfield.field);
					drawing_block(tetra.caller, tetra.phase, tfield.x, tfield.y, 2);
					block_moving(order, &tfield, &tetra);
					if (stopper == 0) {
						block_store(tetra.caller, tetra.phase, tfield.x, tfield.y, tfield.field);
						drawing_block(tetra.caller, tetra.phase, tfield.x, tfield.y, 3);
						ender = 0;
					}
					else {
						block_maker(tetra.caller, tetra.phase, tfield.x, tfield.y, tfield.field);
						drawing_block(tetra.caller, tetra.phase, tfield.x, tfield.y, 1);
					}
				}

				else if (order == TURN_LEFT_1 || order == TURN_LEFT_2 || order == TURN_RIGHT_1 || order == TURN_RIGHT_2) {
					//rotate
					block_eraser(tetra.caller, tetra.phase, tfield.x, tfield.y, tfield.field);
					drawing_block(tetra.caller, tetra.phase, tfield.x, tfield.y, 2);
					block_rotate(order, &tetra.phase);
					// ȸ�� �浹���� ��� �ʿ�
					block_maker(tetra.caller, tetra.phase, tfield.x, tfield.y, tfield.field);
					drawing_block(tetra.caller, tetra.phase, tfield.x, tfield.y, 1);
				}
			}
		}
		stopper = 1;
		ender = 1;
	}

	return 0;
}