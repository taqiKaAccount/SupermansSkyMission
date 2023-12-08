#pragma once
#include <iostream>
#include "ShootingEnemy.hpp"

ShootingEnemy::ShootingEnemy(int x, int y) : Unit(){
    Unit::srcRect = {1383,843,94,129};
    //724,843,95,129
    //gun 41,818,77,155
    Unit::moverRect = {20, 550, 50, 50};
}

bool ShootingEnemy::del_child(){
    if(moverRect.x >= 999){
        return true;
    }
    else{
        return false;
    }
}

// fly() is overrided from the superclass
void ShootingEnemy::fly(){
    // 
    moverRect.x += 15;
    
    if (srcRect.x==724) {
        srcRect.x=1383;
        srcRect.y=843;
        srcRect.w=94;
        srcRect.h=129;
    } else if (srcRect.x==1383) {
        srcRect.x=724;
        srcRect.y=843;
        srcRect.w=95;
        srcRect.h=129;
    } 

}
// these are according to the shootingEnemy.png