#pragma once
#include "Lazer.hpp"

bool Lazer::del_child(){
    if(moverRect.y > 600){
        return true;
    }
    else{
        return false;
    }
}

Lazer::Lazer(int x, int y) : Unit(){
    Unit::srcRect = {71 ,286 ,98, 165};
    Unit::moverRect = {x, y, 50, 50};
}

void Lazer::fly(){
    moverRect.y += 100;
    if (srcRect.x == 71) {
        srcRect.x=71;
        srcRect.y=286;
        srcRect.w=98;
        srcRect.h=165;
        }
}
