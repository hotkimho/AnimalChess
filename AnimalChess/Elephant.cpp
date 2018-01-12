#include "stdafx.h"
#include "Elephant.h"
bool Elephant::move(int first_x, int first_y, int last_x, int last_y) {
	if (last_x<0 || last_x>2 || last_y<0 || last_y>3) {
		return false;
	}
	else if (first_x == last_x && first_y == last_y) return false;
	else {
		if (first_x - 1 == last_x && first_y - 1 == last_y)
			return true;
		else if (first_x + 1 == last_x && first_y - 1 == last_y)
			return true;
		else if (first_x - 1 == last_x && first_y + 1 == last_y)
			return true;
		else if (first_x + 1 == last_x && first_y + 1 == last_y)
			return true;
		else
			return false;
	}
}