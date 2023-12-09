#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Butterfly : public Unit{
    public:
        char name = 'b';
        void fly();
        Butterfly(int x, int y);
    private:
        bool flying_up = false;
        int speed = 2;
};

