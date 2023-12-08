#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"
class blimp : public Unit{
    public:
        char name = 'B';
        void fly();
        blimp(int x, int y);
        bool del_child();

    private:
        bool is_hovering = false;
        int hover_frame = 10;

};
