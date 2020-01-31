#pragma once
#include "constant.h"

typedef struct _block {

	int caller;
	int phase;

} block;

typedef struct _screen {

	int field[HEIGHT][WIDTH];
	int x;
	int y;

} screen;

void block_moving(int direction, screen* s, block* b);
void block_porting(int caller, int phase, int x, int y, int setup, int field[][WIDTH]);
void block_maker(int caller, int phase, int x, int y, int field[][WIDTH]);
void block_eraser(int caller, int phase, int x, int y, int field[][WIDTH]);
void block_store(int caller, int phase, int x, int y, int field[][WIDTH]);
void block_rotate(int direction, int* phase);