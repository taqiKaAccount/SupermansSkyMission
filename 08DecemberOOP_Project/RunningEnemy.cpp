#pragma once
#include <iostream>
#include "RunningEnemy.hpp"

RunningEnemy::RunningEnemy(int x, int y) : Unit(){
    Unit::srcRect = {7,88,160,103};
    Unit::moverRect = {850, 550, 50, 50};
}
//spawn position is set perfectly

bool RunningEnemy::del_child(){
    if(moverRect.x >= 999){
        return true;
    }
    else{
        return false;
    }
}
// fly() is overrided from the superclass
void RunningEnemy::fly(){
    // 
    moverRect.x += speed;
    speed += 0.5; //slowly increase speed as time passes to increase difficulty
    if(moverRect.x > 999){
        moverRect.x = 0;
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
//need to set according to the runningenemy.png