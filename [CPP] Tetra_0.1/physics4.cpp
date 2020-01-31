#include "constant.h"
#include "block.h"
#include <iostream>

// 블럭이 없어서 이동 가능하면 1을 반환
// 불가능하면 0을 반환

using namespace std;

int fourth_physics(int direction, int phase, int x, int y, int field[][WIDTH])
{
	int k = 0;

	if (direction == LEFT)
		k = -1;
	else if (direction == RIGHT)
		k = 1;
	else if (direction == DOWN || direction == SPACE) {
		k = 1;
		goto UPDOWN;
	}
	// 네번째 블럭 좌우 판단
	if (field[y][x + k] == 2)
		return 0;
	else if (field[y][x + 1 + k] == 2)
		return 0;
	else if (field[y + 1][x + k] == 2)
		return 0;
	else if (field[y + 1][x + 1 + k] == 2)
		return 0;
	else
		return 1;

	/* ★■
	   ■■ */ // 회전기능없음

UPDOWN: // 아래 이동 시 물리 판정

	if (field[y + 1 + k][x] == 2)
		return 0;
	else if (field[y + 1 + k][x + 1] == 2)
		return 0;
	else
		return 1;
}