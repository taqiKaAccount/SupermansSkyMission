#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class blimp : public Unit{
    public:
        void fly();
        blimp(int x, int y);
        bool del_child();
};
