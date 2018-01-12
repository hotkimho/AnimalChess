

#include "stdafx.h"
#include "Unit.h"
class EnemyChicken : public Unit {
public:
    EnemyChicken() {}
    EnemyChicken(int id) : Unit(id) {}
    bool move(int first_x, int first_y, int last_x, int last_y);
};
