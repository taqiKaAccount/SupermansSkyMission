#pragma once
#include "Lazer.hpp"


Lazer::Lazer(int x, int y, int lazerType) : Unit(){
    
    Unit::moverRect = {850, 50, 50, 50};

    if (lazerType == 1)
    {
        speed =11
        Unit::srcRect = {307,92,240,86};
        //superman Lazer

    }else{
        speed = - 11
        Unit::srcRect = {307,92,240,86};
        //enemy bullet
        }
    
}
//spawn position for plane is set

bool Lazer::del_child(){
    if(moverRect.x <= 0){
        return true;
    }
    else{
        return false;
    }
}

// fly() is overrided from the superclass
void Lazer::Move(){
    moverRect.y += speed; 

}

