#pragma once
#include "constant.h"

class blockfield {
private:
	int width = WIDTH;
	int height = HEIGHT;
	int* field;
	int field_size;
	int point = 0;
	/*
	0 : empty space
	1 : fixed block
	*/
public:
	blockfield();
	blockfield(int x_max, int y_max);
	~blockfield();
	void print_box();
	void print_block(int* location);
	void clear_block(int* location);
	bool permission(int* location);
	void set_block(int* location);
	void destroy_block(int* location);
	void print_point();
};