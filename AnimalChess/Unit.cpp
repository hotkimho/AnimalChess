#include "stdafx.h"
#include"Unit.h"


Unit::Unit( int id) {
 
    ID = id;
    choice_Check = false;
}


int Unit::getID(){
    return ID;
}

void Unit::setChoiceUp() {
    choice_Check = true;
} 

void Unit::setChoiceDown() {
    choice_Check = false;
}
bool Unit::getChoice() {
    return choice_Check;
}