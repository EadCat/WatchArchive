#pragma once
#include "constant.h"
int first_physics(int direction, int phase, int x, int y, int field[][WIDTH]);
int second_physics(int direction, int phase, int x, int y, int field[][WIDTH]);
int third_physics(int direction, int phase, int x, int y, int field[][WIDTH]);
int fourth_physics(int direction, int phase, int x, int y, int field[][WIDTH]);
int fifth_physics(int direction, int phase, int x, int y, int field[][WIDTH]);
int sixth_physics(int direction, int phase, int x, int y, int field[][WIDTH]);
int seventh_physics(int direction, int phase, int x, int y, int field[][WIDTH]);
int funnel(int caller, int phase, int x, int y, int direction, int field[][WIDTH]);