// blimp.cpp
#pragma once
#include "blimp.hpp"

bool blimp::del_child() {
    if (moverRect.x < 0) {
        return true;
    } else {
        return false;
    }
}

blimp::blimp(int x, int y) : Unit() {
    Unit::srcRect = {1187, 297, 321, 113};
    Unit::moverRect = {850, 300, 100, 60};
}

void blimp::fly() {
    moverRect.x -= speed;

    // Adjust the flying logic based on the direction
    if (flying_up == true) {
        moverRect.y -= (speed / 2);  // Slower speed for blimps

        // Change direction when reaching the top half of the screen
        if (moverRect.y <= 0) {
            flying_up = false;
        }
    } else {
        moverRect.y += (speed / 2);  // Slower speed for blimps

        // Change direction when reaching the bottom of the top half
        if (moverRect.y >= 280) {
            flying_up = true;
        }
    }

    // Adjust the srcRect as needed
    if (srcRect.x == 1187) {
        srcRect.x = 1187;
        srcRect.y = 297;
        srcRect.w = 321;
        srcRect.h = 113;
    }
}




// #pragma once
// #include "blimp.hpp"

// bool blimp::del_child(){
//     if(moverRect.x < 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// blimp::blimp(int x, int y) : Unit(){
//     Unit::srcRect = {1187,297,321,113};
//     Unit::moverRect = {850, 300, 100, 60};
// }
// void blimp::fly(){
//     moverRect.x -= speed;
//     if (srcRect.x == 1187) {
//         srcRect.x=1187;
//         srcRect.y=297;
//         srcRect.w=321;
//         srcRect.h=113;
//         }
// }
// // for collisions doing here 
// // int blimp::getMoverRectX() const {
// //     return moverRect.x;
// // }

// // int blimp::getMoverRectY() const {
// //     return moverRect.y;
// // }


