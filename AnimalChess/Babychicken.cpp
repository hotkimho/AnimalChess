#include "stdafx.h"
#include "Babychicken.h"

bool Babychicken::move(int first_x, int first_y, int last_x, int last_y) {
    if (first_x == last_x && first_y -1 == last_y) {
        return true;
    }
    else return false;
}
