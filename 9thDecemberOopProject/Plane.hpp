#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Plane : public Unit{
    public:
    Plane(int x, int y);
    void fly();
    int speed = 0.5;
    bool del_child();
    //
    // int getMoverRectX() const;
    // int getMoverRectY() const;
};

