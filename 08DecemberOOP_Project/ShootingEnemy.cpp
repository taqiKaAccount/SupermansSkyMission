#pragma once
#include <iostream>
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

void ShootingEnemy::shootingtime(){
    std::cout<<"hi";
    //will call a bullet image or class here idk
    // this changes the image 
    fly(true);
    };

// fly() is overrided from the superclass
void ShootingEnemy::fly(bool takeshot){
    // 
    moverRect.x += speed;
    speed += 0.5; //slowly increase speed as time passes to increase difficulty
    if(moverRect.x > 999){
        moverRect.x = 0;
    }
    if (takeshot)
    //display the shooting image
    {
        srcRect.x=24;
        srcRect.y=147;
        srcRect.w=40;
        srcRect.h=119;
        takeshot = false;
    }
    else if (srcRect.x==608) {
        srcRect.x=322;
        srcRect.y=211;
        srcRect.w=40;
        srcRect.h=54;
    } else if (srcRect.x==322) {
        srcRect.x=608;
        srcRect.y=211;
        srcRect.w=40;
        srcRect.h=54;
    } 

}
