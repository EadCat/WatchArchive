#pragma once
#include "constant.h"

class Tetra {
private:
	int state=0;
	int addset[4][4][2] = { 0, };
	int outset[4][2] = {0, };
	int prediction[4][2] = {0, };
	int range_x;
	int range_y;
	bool destroy=false;

public:
	// Method Summary
	Tetra(int kind, int x_init, int y_init, int state, int width = WIDTH, int height = HEIGHT);
	~Tetra();
	int* addr(); // access current block position!!
	void rotate_left(bool permission=true);
	void rotate_right(bool permission = true);
	void move_down(bool permission = true);
	void move_left(bool permission = true);
	void move_right(bool permission = true);
	
	int* rotate_predict(int next_turn);
	// return &prediction[0][0], size = 8 * int;
	int* move_predict(int next_move);
	bool destruction_command();
};

// b.move_down(a.permission(b.move_predict(command)))