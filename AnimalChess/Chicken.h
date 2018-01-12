

#include "stdafx.h"
#include "Unit.h"
class Chicken : public Unit {
public:
    Chicken() {}
    Chicken(int id) : Unit(id) {}
    bool move(int first_x, int first_y, int last_x, int last_y);
};
