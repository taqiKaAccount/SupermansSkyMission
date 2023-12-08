#pragma once
#include "Plane.hpp"


Plane::Plane(int x, int y) : Unit(){
    Unit::srcRect = {7,88,160,103};
    Unit::moverRect = {850, 50, 50, 50};
}
//spawn position for plane is set

// fly() is overrided from the superclass
void Plane::fly(){
    // 
    moverRect.x += speed;
    speed += speed; 
    if(moverRect.x > 999){
        moverRect.x = 0;
    } 
    if (srcRect.x==7) {
        srcRect.x=0;
        srcRect.y=237;
        srcRect.w=153;
        srcRect.h=84;
    } else if (srcRect.x==0) {
        srcRect.x=2;
        srcRect.y=361;
        srcRect.w=159;
        srcRect.h=124;
    } else if (srcRect.x==2) {
        srcRect.x=7;
        srcRect.y=88;
        srcRect.w=155;
        srcRect.h=103;
    }

}

