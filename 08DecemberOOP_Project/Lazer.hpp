#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Lazer : public Unit{

    public:
    Lazer(int x, int y);
    void fly();
    int speed = 11;
    bool del_child();
};
