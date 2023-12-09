#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Lazer : public Unit{
    public:
        void fly();
        Lazer(int x, int y);
        bool del_child();
};
