#include "field.h"
#include "console.h"
#include "block.h"

#include <iostream>
#include <algorithm>

blockfield::blockfield() {
	field = new int[WIDTH * HEIGHT];
	field_size = WIDTH * HEIGHT;
	for (int i = 0; i < field_size; i++) {
		field[i] = 0;
	}
}
blockfield::blockfield(int x_max, int y_max) {
	this->width = x_max;
	this->height = y_max;
	field = new int[x_max * y_max];
	field_size = x_max * y_max;
	for (int i = 0; i < field_size; i++) {
		field[i] = 0;
	}
}
blockfield::~blockfield() {
	delete[] field;
}
void blockfield::print_box() {
	for (int i = 0; i <= height; i++) {
		gotoxy_Wall(0, i);
		for (int j = 0; j < width + 2; j++) {
			if (j == 0 || j == width + 1 || i == height)
				std::cout << "в╠";
			else
				std::cout << "  ";
		}
	}
}

void blockfield::print_block(int* location) {
	int i = 0;
	while (i < 8) {
		gotoxy_Block(location[i], location[i + 1]);
		std::cout << "бр";
		i += 2;
	}
}

void blockfield::clear_block(int* location) {
	int i = 0;
	while (i < 8) {
		gotoxy_Block(location[i], location[i + 1]);
		std::cout << "  ";
		i += 2;
	}
}

bool blockfield::permission(int* location) {
	int i = 0;
	int* ptr = location; // &prediction[0][0]
	while (i < 8) {
		if (field[*(ptr+i) + width*(*(ptr+i+1))] == 1)
			return false;
		i += 2;
	}
	return true;
}

void blockfield::set_block(int* location) {
	int i = 0;
	int* ptr = location;
	while (i < 8) {
		this->field[*(ptr+i) + width*(*(ptr+i+1))] = 1; // values setting
		gotoxy_Block(*(ptr+i), *(ptr+i+1));
		std::cout << "бс";
		i += 2;
	}
}

void blockfield::destroy_block(int* location) {
	int x;
	int y[4];
	int y_t;
	int i,j;
	int checker = 0;
	j = 0;
	for (i = 0; i < 8; i+=2) {
		y[j] = location[i+1]; // extract changed height location
		j++;
	}
	std::sort(y, y + 4);

	for (i = 0; i < 4; i++) { 
		if (i > 4) { // Omit duplicate y coordinate process
			if (y[i] == y[i + 1])
				continue;
		}
		for (x = 0; x < width; x++) { // check full line
			if (field[width * y[i] + x] == 1) {
				checker++;
			}
		}
		if (checker == width) { // destruction order
			point += width;
			gotoxy_Block(0, y[i]);
			for (j = 0; j < width; j++) {
				std::cout << "  "; // cleaning
			}
			for (j = y[i]; j > 0; j--) { // field check
				for (x = 0; x < width; x++) {
					field[j * width + x] = 0;
					if (field[(j-1) * width + x] == 1) { // if there is a block,
						field[j * width + x] = 1;
						field[(j - 1) * width + x] = 0; // push down datas
						gotoxy_Block(x, j); std::cout << "бс";
						gotoxy_Block(x, j - 1); std::cout << "  "; // draw blocks
					}
				}
			}
		}
		checker = 0;
	}
}
void blockfield::print_point() {
	gotoxy(movingPoint_x, movingPoint_y+1);
	std::cout << "                    ";
	gotoxy(movingPoint_x, movingPoint_y+1);
	std::cout << this->point;
}