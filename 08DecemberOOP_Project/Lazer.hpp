#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Lazer : public Unit{
    private:
    int speed;

    public:
    Lazer(int x, int y, int lazerType);

    void Move();
    bool del_child();
};
// we can use one function for superman lazer and for the bullet
