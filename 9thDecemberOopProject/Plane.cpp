#pragma once
#include "Plane.hpp"


Plane::Plane(int x, int y) : Unit(){
    Unit::srcRect = {307,92,240,86};
    Unit::moverRect = {850, 50, 75, 75};
}
//spawn position for plane is set

bool Plane::del_child(){
    if(moverRect.x <= 0){
        return true;
    }
    else{
        return false;
    }
}

// fly() is overrided from the superclass
void Plane::fly(){
    if (srcRect.x == 307) {
        srcRect.x=594;
        srcRect.y=92;
        srcRect.w=239;
        srcRect.h=88;

    } else if (srcRect.x == 594) {
        srcRect.x=888;
        srcRect.y=92;
        srcRect.w=239;
        srcRect.h=88;

    } else if (srcRect.x == 888){
        srcRect.x=307;
        srcRect.y=92;
        srcRect.w=240;
        srcRect.h=86;
    }

    moverRect.x -= speed+rand()%10; 

}

