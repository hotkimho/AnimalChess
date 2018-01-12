
#ifndef __UNIT_H__
#define __UNIT_H__

class Unit {
public :
    int ID;
    bool choice_Check;
public :
    Unit() {}
    Unit(int id);
    virtual ~Unit() {}
    void setX(int a);
    void setY(int a);
    int getX();
    int getY();
    int getID();
    void setChoiceUp();
    void setChoiceDown();
    bool getChoice();
    virtual bool move(int first_x, int first_y,int last_x,int last_y) = 0;
};
#endif