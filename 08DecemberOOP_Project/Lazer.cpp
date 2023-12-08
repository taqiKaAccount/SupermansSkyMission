#pragma once
#include "Lazer.hpp"


Lazer::Lazer(int x, int y, int lazerType) : Unit(){
    
    Unit::moverRect = {x, y, 50, 50};
    // want the x, y vals to be the moverrect of either superman or the enemy

    if (lazerType == 1)
    {
        speed =11
        Unit::srcRect = {71, 286, 98, 165};
        //superman Lazer

    }else{
        speed = - 11
        Unit::srcRect = {243, 863, 27, 38};
        //enemy bullet
        }
    
}
//spawn position for plane is set

bool Lazer::del_child(){
    if(moverRect.y >= 650 or moverRect.y <= 0){
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

