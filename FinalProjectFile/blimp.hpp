#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class blimp : public Unit{
    int speed = 15;
    bool flying_up = false;
    public:
        void fly();
        blimp(int x, int y);
        bool del_child();
};
