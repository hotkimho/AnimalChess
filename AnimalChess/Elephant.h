
#include "Unit.h"
#include "stdafx.h"

class Elephant : public Unit {
public:
    Elephant() {}
    Elephant(int id) : Unit(id) {}
    bool move(int first_x, int first_y, int last_x, int last_y);
};

