#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Pigeon : public Unit{
    public:
    char name = 'p';
    Pigeon(int x, int y);
    void fly();
    int speed = 0.5;
};

