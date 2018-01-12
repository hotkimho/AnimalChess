

#include "stdafx.h"
#include "Unit.h"
class Babychicken : public Unit {
public:
    Babychicken() {}
    Babychicken(int id) : Unit(id) {}
    bool move(int first_x, int first_y, int last_x, int last_y);
};
