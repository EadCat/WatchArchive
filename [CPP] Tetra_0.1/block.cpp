#include "constant.h"
#include "block.h"
#include "physics.h"
#include <iostream>
#include <conio.h>

using namespace std;

/*=========================
목록
1. 방향키 받고 x, y 좌표 이동 함수
	(충돌 판정 필요)
2. 필드를 1로 실시간 포팅 함수
3. 필드를 0으로 실시간 포팅 함수
4. 재활용 포팅 함수
=========================*/

void block_moving(int direction, screen* s, block* b)
{// 콜러랑 페이즈 받아서 조건 탐색

	if (direction == DOWN && funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
		(s->y)++;
	} // 아래 이동
	else if (direction == LEFT && funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
		(s->x)--;
	} // 왼쪽 이동
	else if (direction == RIGHT && funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
		(s->x)++;
	} // 오른쪽 이동
	else if (direction == SPACE) {
		while (funnel(b->caller, b->phase, s->x, s->y, direction, s->field)) {
			(s->y)++;
		}
	}
	// 방향키 입력에 따라 x, y 좌표 변화를 가함.
}

// Axis (★)를 기준으로 값을 부여함
void block_maker(int caller, int phase, int x, int y, int field[][WIDTH]) {
	block_porting(caller, phase, x, y, 1, field);
} // 그리기 위하여 필드 값을 1로 포팅

void block_eraser(int caller, int phase, int x, int y, int field[][WIDTH]) {
	block_porting(caller, phase, x, y, 0, field);
} // 지우기 위하여 필드 값을 0으로 포팅

void block_store(int caller, int phase, int x, int y, int field[][WIDTH]) {
	block_porting(caller, phase, x, y, 2, field);
} // 축적하기 위하여 필드 값을 2로 포팅

void block_rotate(int direction, int* phase) {
	if (direction == TURN_LEFT_1 || direction == TURN_LEFT_2) {
		(*phase)--;
		if ((*phase) == 0)
			(*phase) = 4;
	} // a 왼쪽 회전
	else if (direction == TURN_RIGHT_1 || direction == TURN_RIGHT_2) {
		(*phase)++;
		if ((*phase) == 5)
			(*phase) = 1;
	} // s 오른쪽 회전
} // 블럭 회전 (재생성 필요)

void block_porting(int caller, int phase, int x, int y, int setup, int field[][WIDTH])
{ // setup 값으로 해당 필드를 포팅하는 함수
	if (caller == 1) {
		if (phase == 1) {
			field[y][x] = setup; // star
			field[y][x - 1] = setup;
			field[y][x + 1] = setup;
			field[y + 1][x - 1] = setup;
		} /* ■★■
			 ■     */
		else if (phase == 2) {
			field[y][x] = setup; // star
			field[y][x - 1] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
		} /* ■★
			   ■
			   ■ */
		else if (phase == 3) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x - 2] = setup;
		} /*    ★
			■■■*/
		else if (phase == 4) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 2][x + 1] = setup;
		} /* ★
			 ■
			 ■■ */
		else
			cout << "\nillegal phase input.\n";
	}

	else if (caller == 2) {
		if (phase == 1) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
			field[y + 1][x + 2] = setup;
		} /* ★
			 ■■■ */
		else if (phase == 2) {
			field[y][x] = setup; // star
			field[y][x + 1] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
		} /* ★■
			 ■
			 ■ */
		else if (phase == 3) {
			field[y][x] = setup; // star
			field[y][x + 1] = setup;
			field[y][x + 2] = setup;
			field[y + 1][x + 2] = setup;
		} /*★■■
				■*/
		else if (phase == 4) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 2][x - 1] = setup;
		} /* ★
			 ■
		   ■■ */
		else
			cout << "\nillegal phase input.\n";
	}

	else if (caller == 3) {
		if (phase == 1) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x + 1] = setup;
		} /* ★
		   ■■■*/
		else if (phase == 2) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
			field[y + 2][x] = setup;
		} /*★
			■■
			■*/
		else if (phase == 3) {
			field[y][x] = setup; // star
			field[y][x - 1] = setup;
			field[y][x + 1] = setup;
			field[y + 1][x] = setup;
		} /*■★■
			  ■*/
		else if (phase == 4) {
			field[y][x] = setup; // star
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 1][x - 1] = setup;
		} /* ★
		   ■■
			 ■*/
		else
			cout << "\nillegal phase input.\n";
	}

	// 무회전 블록 ****************************************************************
	else if (caller == 4) {
		field[y][x] = setup;
		field[y][x + 1] = setup;
		field[y + 1][x] = setup;
		field[y + 1][x + 1] = setup;
	}
	/* ★■
	   ■■ */ // 회전기능없음

	   // 여기부터 2회전 ***************************************************************
	else if (caller == 5) {
		if (phase % 2 == 0) {
			field[y][x] = setup;
			field[y][x + 1] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x] = setup;
		}
		/* ★■
		 ■■*/
		else {
			field[y][x] = setup;
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
			field[y + 2][x + 1] = setup;
		} /* ★
			 ■■
			   ■*/
	}

	else if (caller == 6) {
		if (phase % 2 == 0) {
			field[y][x] = setup;
			field[y][x - 1] = setup;
			field[y + 1][x] = setup;
			field[y + 1][x + 1] = setup;
		} /* ■★
		 	   ■■*/
		else {
			field[y][x] = setup;
			field[y + 1][x - 1] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x - 1] = setup;
		} /*   ★
			 ■■
			 ■   */
	}
	
	else if (caller == 7) {
		if (phase % 2 == 0) {
			field[y][x] = setup;
			field[y][x - 1] = setup;
			field[y][x + 1] = setup;
			field[y][x + 2] = setup;
		}
		// ■★■■
		else {
			field[y][x] = setup;
			field[y + 1][x] = setup;
			field[y + 2][x] = setup;
			field[y + 3][x] = setup;
		}
		/* ★
		   ■
		   ■
		   ■ */
	}

	else {
		cout << "\nillegal caller input value!\n";
		exit(1);
	}
}