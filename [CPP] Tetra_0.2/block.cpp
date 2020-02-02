#include "block.h"
#include <iostream>

Tetra::Tetra(int kind, int x_init, int y_init, int state, int width, int height) {
	this->state = state;
	int x = x_init;
	int y = y_init;
	this->range_x = width;
	this->range_y = height;

	int address[7][4][4][2] = {
		{{ {x, y}, {x - 1, y + 1}, { x, y + 1 }, {x + 1, y + 1} },
		{ {x, y}, { x, y + 1 }, {x + 1, y + 1}, {x, y + 2} },
		{ {x, y + 1}, { x - 1, y + 1 }, { x + 1, y + 1 }, {x, y + 2} },
		{ {x, y}, { x, y + 1 }, {x - 1, y + 1}, {x, y + 2} }},

		{{{x, y}, {x + 1,y},{x + 1,y + 1},{x + 1,y + 2}} ,
		{ {x,y},{x,y + 1},{x - 1,y + 1},{x - 2,y + 1} },
		{ {x,y},{x,y + 1},{x,y + 2},{x + 1,y + 2} },
		{ {x,y},{x,y + 1},{x + 1,y},{x + 2,y} } },

		{ {{x,y}, {x + 1,y}, {x,y + 1}, {x,y + 2}},
		  {{x,y}, {x + 1,y}, {x + 2,y}, {x + 2,y + 1}},
		  {{x,y}, {x,y + 1}, {x,y + 2}, {x - 1,y + 2}},
		  {{x,y}, {x,y + 1}, {x + 1,y + 1}, {x + 2,y + 1}} },

		  { {{x,y}, {x,y + 1}, {x + 1,y}, {x + 1,y + 1}},
		  {{x,y}, {x,y + 1}, {x + 1,y}, {x + 1,y + 1}},
		  {{x,y}, {x,y + 1}, {x + 1,y}, {x + 1,y + 1}},
		  {{x,y}, {x,y + 1}, {x + 1,y}, {x + 1,y + 1}} },

		  { {{x,y}, {x,y + 1}, {x,y + 2}, {x,y + 3}},
		  {{x - 1,y}, {x,y}, {x + 1,y}, {x + 2,y}},
		  {{x,y}, {x,y + 1}, {x,y + 2}, {x,y + 3}},
		  {{x - 1,y}, {x,y}, {x + 1,y}, {x + 2,y}} },

		  { {{x,y}, {x,y + 1}, {x + 1,y + 1}, {x + 1,y + 2}},
		  {{x,y}, {x + 1,y}, {x,y + 1}, {x - 1,y + 1}},
		  {{x,y}, {x,y + 1}, {x + 1,y + 1}, {x + 1,y + 2}},
		  {{x,y}, {x + 1,y}, {x,y + 1}, {x - 1,y + 1}} },

		  { {{x,y}, {x,y + 1}, {x - 1,y + 1}, {x - 1,y + 2}},
		  {{x,y}, {x - 1,y}, {x,y + 1}, {x + 1,y + 1}},
		  {{x,y}, {x,y + 1}, {x - 1,y + 1}, {x - 1,y + 2}},
		  {{x,y}, {x - 1,y}, {x,y + 1}, {x + 1,y + 1}} } };

	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				this->addset[i][j][k] = address[kind][i][j][k];
			}
		}
	}
}

Tetra::~Tetra() {
	// outset 좌표 값은 field class 에 리턴하고 destroy.
	delete[] this->addset;
	delete[] this->outset;
	delete[] this->prediction;
}

int* Tetra::addr() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			this->outset[i][j] = this->addset[this->state][i][j];
		}
	}
	return &outset[0][0];
}

void Tetra::rotate_left(bool permission) {
	bool recovery = !permission;
	this->state -= 1;
	if (this->state == -1)
		this->state = 3;
	for (int i = 0; i < 4; i++) {
		if (addset[this->state][i][0] < 0 || addset[this->state][i][0] >= this->range_x) {
			recovery = true; break;
		}	
	}
	for (int i = 0; i < 4; i++) {
		if (addset[this->state][i][1] >= this->range_y) {
			recovery = true; break;
		}
	}
	if (recovery) {
		this->state += 1;
		if (this->state == 4)
			this->state = 0;
	}
		
}
void Tetra::rotate_right(bool permission) {
	bool recovery = !permission;
	this->state += 1;
	if (this->state == 4)
		this->state = 0;
	for (int i = 0; i < 4; i++) {
		if (addset[this->state][i][0] < 0 || addset[this->state][i][0] >= this->range_x) {
			recovery = true; break;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (addset[this->state][i][1] >= this->range_y) {
			recovery = true; break;
		}
	}
	if (recovery) {
		this->state -= 1;
		if (this->state == -1)
			this->state = 3;
	}
}

void Tetra::move_down(bool permission) {
	bool permit = permission;
	// Wall Check
	for (int i = 0; i < 4; i++) {
		if (this->addset[this->state][i][1] == this->range_y-1) {
			permit = false;
			this->destroy = true;
		}
	}
	// move
	if (permit) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->addset[i][j][1] += 1;
			}
		}
	}
	else {
		this->destroy = true;
	}
}

void Tetra::move_left(bool permission) {
	bool permit = permission;
	// Wall Check
	for (int i = 0; i < 4; i++) {
		if (this->addset[this->state][i][0] == 0)
			permit = false;
	}
	// move
	if (permit) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->addset[i][j][0] -= 1;
			}
		}
	}
}

void Tetra::move_right(bool permission) {
	bool permit = permission;
	// Wall Check
	for (int i = 0; i < 4; i++) {
		if (this->addset[this->state][i][0] == this->range_x-1)
			permit = false;
	}
	// move
	if (permit) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->addset[i][j][0] += 1;
			}
		}
	}
}

int* Tetra::rotate_predict(int next_turn) {
	int tmp = this->state;
	if (next_turn == A_key || next_turn == a_key)
		tmp -= 1;
	else if (next_turn == D_key || next_turn == d_key)
		tmp += 1;
	if (tmp == 4)
		tmp = 0;
	else if (tmp == -1)
		tmp = 3;
	// 예측 회전 모형을 카피하여 리턴
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			this->prediction[i][j] = this->addset[tmp][i][j];
		}
	}
	return &prediction[0][0];
}

int* Tetra::move_predict(int next_move) {
	// current position copy
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			prediction[i][j] = addset[this->state][i][j];
		}
	}
	// prediction
	if (next_move == LEFT) {
		for (int i = 0; i < 4; i++)
			prediction[i][0] -= 1;
	}
	else if (next_move == RIGHT) {
		for (int i = 0; i < 4; i++)
			prediction[i][0] += 1;
	}
	else if (next_move == DOWN) {
		for (int i = 0; i < 4; i++)
			prediction[i][1] += 1;
	}

	return &prediction[0][0];
}

bool Tetra::destruction_command() {
	return this->destroy;
}