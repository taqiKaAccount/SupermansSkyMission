#pragma once
#include "butterfly.hpp"


Butterfly::Butterfly(int x, int y) : Unit(){
    Unit::srcRect = {256, 24, 174, 134};
    Unit::moverRect = {700, 600, 50, 50};
}

void Butterfly::fly(){
    if (srcRect.y == 24) {
        srcRect.x=257;
        srcRect.y=182;
        srcRect.w=192;
        srcRect.h=214;

    } else if (srcRect.y == 182) {
        srcRect.x=248;
        srcRect.y=433;
        srcRect.w=247;
        srcRect.h=178;

    } else if (srcRect.y == 433){
        srcRect.x=256;
        srcRect.y=24;
        srcRect.w=174;
        srcRect.h=134;
    }

    moverRect.x += speed+rand()%10; 

    if(moverRect.x > 999){
        moverRect.x = -20;
    }
    if(flying_up == true){
        if(moverRect.y >= 0){
            moverRect.y -= speed+rand()%10;
        } 
        else if(moverRect. y < 0){
            moverRect.y += speed+rand()%10;
            flying_up = false;
            }
    }
    else if(flying_up == false){
        if(moverRect.y <= 560) {
            moverRect.y += speed+rand()%10;
        }
        else if(moverRect.y > 560){
        moverRect.y -= speed + rand()%10; 
        flying_up = true;
        }
    }

}
