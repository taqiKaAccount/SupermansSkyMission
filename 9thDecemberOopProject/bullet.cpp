#pragma once
#include "bullet.hpp"

bool bullet::del_child(){
    if(moverRect.y > 0){
        return true;
    }
    else{
        return false;
    }
}

bullet::bullet(int x, int y) : Unit(){
    Unit::srcRect = {243,863,27,38};
    Unit::moverRect = {x, y, 50, 50};
}

void bullet::fly(){
    moverRect.y += 100;
    if (srcRect.x == 243) {
        srcRect.x=243;
        srcRect.y=863;
        srcRect.w=27;
        srcRect.h=38;
        }
}
