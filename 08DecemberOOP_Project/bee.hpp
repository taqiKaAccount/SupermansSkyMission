#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class Bee : public Unit{
    public:
        char name = 'd';
        void fly();
        Bee(int x, int y);
        bool del_child();

    private:
        bool is_hovering = false;
        int hover_frame = 10;

};
