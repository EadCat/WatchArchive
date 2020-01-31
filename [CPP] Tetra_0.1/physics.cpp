#include "physics.h"
#include <iostream>

using namespace std;

extern int stopper;

int funnel(int caller, int phase, int x, int y, int direction, int field[][WIDTH])
{
	if (caller == 1) {
		if ((direction == DOWN || direction == SPACE) && first_physics(direction, phase, x, y, field) == 0)
			stopper = 0;
		return first_physics(direction, phase, x, y, field);
	}

	else if (caller == 2) {
		if ((direction == DOWN || direction == SPACE) && second_physics(direction, phase, x, y, field) == 0)
			stopper = 0;
		return second_physics(direction, phase, x, y, field);
	}

	else if (caller == 3) {
		if ((direction == DOWN || direction == SPACE) && third_physics(direction, phase, x, y, field) == 0)
			stopper = 0;
		return third_physics(direction, phase, x, y, field);
	}
		
	else if (caller == 4) {
		if ((direction == DOWN || direction == SPACE) && fourth_physics(direction, phase, x, y, field) == 0)
			stopper = 0;
		return fourth_physics(direction, phase, x, y, field);
	}
		
	else if (caller == 5) {
		if ((direction == DOWN || direction == SPACE) && fifth_physics(direction, phase, x, y, field) == 0)
			stopper = 0;
		return fifth_physics(direction, phase, x, y, field);
	}
		
	else if (caller == 6) {
		if ((direction == DOWN || direction == SPACE) && sixth_physics(direction, phase, x, y, field) == 0)
			stopper = 0;
		return sixth_physics(direction, phase, x, y, field);
	}
		
	else if (caller == 7) {
		if ((direction == DOWN || direction == SPACE) && seventh_physics(direction, phase, x, y, field) == 0)
			stopper = 0;
		return seventh_physics(direction, phase, x, y, field);
	}
		
	else {
		cout << "\nillegal funnel input.\n";
		return 0;
	}
}