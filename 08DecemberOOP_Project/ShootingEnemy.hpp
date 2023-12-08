#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "unit.hpp"

class ShootingEnemy : public Unit{
    public:
    char name = 'S';
    bool del_child();
    ShootingEnemy(int x = 0, int y = 0);
    void shootingtime();
    void fly();
    int speed = 0.5;
};
