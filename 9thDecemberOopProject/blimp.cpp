#pragma once
#include "blimp.hpp"

bool blimp::del_child(){
    if(moverRect.x < 0){
        return true;
    }
    else{
        return false;
    }
}

blimp::blimp(int x, int y) : Unit(){
    Unit::srcRect = {1187,297,321,113};
    Unit::moverRect = {850, 300, 100, 60};
}
void blimp::fly(){
    moverRect.x -= 15;
    if (srcRect.x == 1187) {
        srcRect.x=1187;
        srcRect.y=297;
        srcRect.w=321;
        srcRect.h=113;
        }
}


