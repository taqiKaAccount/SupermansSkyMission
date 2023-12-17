// blimp.cpp
#pragma once
#include "blimp.hpp"

bool blimp::del_child() {
    if (moverRect.x < 0) {
        return true;
    } else {
        return false;
    }
}

blimp::blimp(int x, int y) : Unit() {
    Unit::srcRect = {1187, 297, 321, 113};
    Unit::moverRect = {850, rand()%300, 100, 60};
}

void blimp::fly() {
    moverRect.x -= speed;
    speed = speed + 0.25 ; 
        // Change direction when reaching the bottom of the top half

    // Adjust the srcRect as needed
    if (srcRect.x == 1187) {
        srcRect.x = 1187;
        srcRect.y = 297;
        srcRect.w = 321;
        srcRect.h = 113;
    }
}




