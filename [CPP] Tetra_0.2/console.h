#pragma once
#include "constant.h"

void gotoxy(int x, int y);
void gotoxy_Wall(int x, int y, int xlim = SpacePadding_x, int ylim = SpacePadding_y);
void gotoxy_Block(int x, int y, int xlim = SpacePadding_x + BoxPadding_x, int ylim = SpacePadding_y + BoxPadding_y);
void NoCursor();