#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "unit.hpp"

class RunningEnemy : public Unit{
    public:
    char name = 'R';
    bool del_child();
    RunningEnemy(int x = 0, int y = 0);
    void fly();
    int speed = 0.5;
};
