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
    Unit::srcRect = {0, 234, 162, 109};
    Unit::moverRect = {20, 750, 50, 50};
}
void Blimp::fly(){
    if (srcRect.x==0) {
        srcRect.x=234;
        srcRect.y=630;
        srcRect.w=163;
        srcRect.h=162;
        
    } 
    else if (srcRect.x==234 ) {
        srcRect.x=409;
        srcRect.y=650;
        srcRect.w=171;
        srcRect.h=147;
        
    } 
    else{
        srcRect.x=63;
        srcRect.y=619;
        srcRect.w=151;
        srcRect.h=166;
        
    }

    if (!is_hovering) {
        moverRect.x += 5;
        int n = rand() % 100;
        switch (n) {
            case 73:
            case 37:
            case 69:
            case 42:
            case 13:
                is_hovering = true;
                break;
        }
    }
    else {
        if (hover_frame != 0) {
            hover_frame-=1;
        } 
        else {
            is_hovering = false;
            hover_frame = 10;
        }
    }
}


