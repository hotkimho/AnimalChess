
#include "stdafx.h"
#include "Unit.h"
class Kirin : public Unit {
public:
    Kirin() {}
    Kirin( int id) : Unit(id) {}
    bool move(int first_x, int first_y, int last_x, int last_y);
};
