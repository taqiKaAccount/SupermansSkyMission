#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class bullet : public Unit{
    public:
        void fly();
        bullet(int x, int y);
        bool del_child();
};
