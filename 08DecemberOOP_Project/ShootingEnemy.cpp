#pragma once
#include "ShootingEnemy.hpp"

ShootingEnemy::ShootingEnemy(int x, int y) : Unit(){
    Unit::srcRect = {7,88,160,103};
    Unit::moverRect = {x, y, 50, 50};
}

bool ShootingEnemy::del_child(){
    if(moverRect.x >= 999){
        return true;
    }
    else{
        return false;
    }
}

void ShootingEnemy::shootingtime(){std::cout<<"hi"};

// fly() is overrided from the superclass
void ShootingEnemy::fly(){
    // 
    moverRect.x += speed;
    speed += 0.5; //slowly increase speed as time passes to increase difficulty
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
