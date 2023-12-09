#pragma once
#include <iostream>
#include "RunningEnemy.hpp"

RunningEnemy::RunningEnemy(int x, int y) : Unit(){
    Unit::srcRect = {334,588,126,148};
    //26,589,147,152
    // Unit::moverRect = {850, 550, 50, 60};
    Unit::moverRect = {850, 550, 120, 80};

}
//spawn position is set perfectly

bool RunningEnemy::del_child(){
    if(moverRect.x <= 0){
        return true;
    }
    else{
        return false;
    }
}

// fly() is overrided from the superclass
void RunningEnemy::fly(){
    // 
    moverRect.x -= 15; 
     //slowly increase speed as time passes to increase difficulty
    if (srcRect.x==334) {
        srcRect.x=26;
        srcRect.y=589;
        srcRect.w=147;
        srcRect.h=152;
    } else if (srcRect.x==26) {
        srcRect.x=334;
        srcRect.y=588;
        srcRect.w=126;
        srcRect.h=148;
    }

}
//need to set according to the runningenemy.png
