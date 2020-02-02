#include "timer.h"

#define gap_1 1

bool cooltime(time_t forward, time_t delta) {
	if (difftime(forward, delta) >= gap_1)
		return true;
	else
		return false;
}