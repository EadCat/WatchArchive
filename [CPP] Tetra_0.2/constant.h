#pragma once

// Draw parameters
#define WIDTH 11
#define HEIGHT 17
#define SpacePadding_x 5
#define SpacePadding_y 5
#define BoxPadding_x 1
#define BoxPadding_y 0
#define PointPadding_x 3
#define PointPadding_y 6
#define movingPoint_x (WIDTH+SpacePadding_x+PointPadding_x)
#define movingPoint_y (PointPadding_y+SpacePadding_y)
#define Title_x SpacePadding_x + int(WIDTH/3)-2
#define Title_y int(SpacePadding_y/2)
#define ResultPrint (SpacePadding_y+HEIGHT+3)

// ASCII Code
#define ESC 27
#define A_key 65
#define a_key 97
#define D_key 68
#define d_key 100
#define S_key 83
#define s_key 115
#define W_key 87
#define w_key 119
#define SPACE 32
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77