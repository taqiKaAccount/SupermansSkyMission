#pragma once
#include "Blimp.hpp"

bool Blimp::del_child(){
    if(moverRect.x >= 999){
        return true;
    }
    else{
        return false;
    }
}

Blimp::Blimp(int x, int y) : Unit(){
    Unit::srcRect = {1187,297,321,113};
    Unit::moverRect = {20, 750, 50, 50};
}
void Blimp::fly(){
    moverRect.x -= 5;
}


