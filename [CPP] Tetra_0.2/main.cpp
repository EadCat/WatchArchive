#include "field.h"
#include "block.h"
#include "console.h"
#include "constant.h"
#include "conio.h"
#include "timer.h"

#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
	blockfield field;
	Tetra* block_ptr = NULL;
	int command = NULL;
	int selector, state;
	time_t forward = time(NULL);
	time_t delta = time(NULL);

	NoCursor(); // Cursor Hiding Function
	srand(time(NULL)); // random seed setting
	gotoxy(Title_x, Title_y);
	std::cout << "<<EadCat Tetra 0.2v>>";
	gotoxy(movingPoint_x, movingPoint_y);
	std::cout << "Your Point";

	field.print_box();
	while (1) {
		selector = rand() % 7;
		state = rand() % 4;
		block_ptr = new Tetra(selector, WIDTH / 2, NULL, state);
		field.print_block(block_ptr->addr());
		if (field.permission(block_ptr->move_predict(DOWN)) == false) {
			field.set_block(block_ptr->addr());
			break;
		}
		while (1) {
			field.print_block(block_ptr->addr());
			/* ===================================Gravity===================================== */
			forward = time(NULL);
			if (cooltime(forward, delta)) {
				delta = time(NULL);
				field.clear_block(block_ptr->addr());
				block_ptr->move_down(field.permission(block_ptr->move_predict(DOWN)));
				if (block_ptr->destruction_command()) {
					field.set_block(block_ptr->addr());
					break;
				}
			}
			/*=================================================================================*/
			
			/*==================================User Control===================================*/
			if (_kbhit()) {
				command = _getch();
				if (command == A_key || command == a_key) {
					field.clear_block(block_ptr->addr());
					block_ptr->rotate_left(field.permission(block_ptr->rotate_predict(command)));
				}
				else if (command == D_key || command == d_key) {
					field.clear_block(block_ptr->addr());
					block_ptr->rotate_right(field.permission(block_ptr->rotate_predict(command)));
				}
				else if (command == DOWN) {
					field.clear_block(block_ptr->addr());
					block_ptr->move_down(field.permission(block_ptr->move_predict(command)));
					if (block_ptr->destruction_command()) {
						field.set_block(block_ptr->addr());
						field.destroy_block(block_ptr->addr());
						field.print_point();
						break;
					}
				}
				else if (command == SPACE) {
					field.clear_block(block_ptr->addr());
					while (1) {
						if (block_ptr->destruction_command()) {
							field.set_block(block_ptr->addr());
							field.destroy_block(block_ptr->addr());
							field.print_point();
							break;
						}
						block_ptr->move_down(field.permission(block_ptr->move_predict(DOWN)));
					}
					break;
				}
				else if (command == LEFT) {
					field.clear_block(block_ptr->addr());
					block_ptr->move_left(field.permission(block_ptr->move_predict(command)));
				}
				else if (command == RIGHT) {
					field.clear_block(block_ptr->addr());
					block_ptr->move_right(field.permission(block_ptr->move_predict(command)));
				}
			}
			/*==================================User Control===================================*/
		}
	}

	gotoxy(Title_x, ResultPrint);
	std::cout << "Game End" << "\n\n";
	return 0;
}