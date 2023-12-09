#include "Plane.hpp"

Plane::Plane(int x, int y) : Unit() {
    Unit::srcRect = {307, 92, 240, 86};
    Unit::moverRect = {850, 50, 75, 50};
}

bool Plane::del_child() {
    if (moverRect.x <= 0) {
        return true;
    } else {
        return false;
    }
}
void Plane::fly() {
    if (srcRect.x == 307) {
        srcRect.x = 594;
        srcRect.y = 92;
        srcRect.w = 239;
        srcRect.h = 88;
    } else if (srcRect.x == 594) {
        srcRect.x = 888;
        srcRect.y = 92;
        srcRect.w = 239;
        srcRect.h = 88;
    } else if (srcRect.x == 888) {
        srcRect.x = 307;
        srcRect.y = 92;
        srcRect.w = 240;
        srcRect.h = 86;
    }

    // Adjust the flying logic based on the direction
    if (flying_up == true) {
        moverRect.y -= speed + rand() % 10;
        
        // Change direction when reaching the top half of the screen
        if (moverRect.y <= 0) {
            flying_up = false;
        }
    } else {
        moverRect.y += speed + rand() % 10;
        
        // Change direction when reaching the bottom of the top half
        if (moverRect.y >= 280) {
            flying_up = true;
        }
    }

    moverRect.x -= speed + rand() % 10;
}












// #pragma once
// #include "Plane.hpp"


// Plane::Plane(int x, int y) : Unit(){
//     Unit::srcRect = {307,92,240,86};
//     Unit::moverRect = {850, 50, 75, 50};
// }
// //spawn position for plane is set

// bool Plane::del_child(){
//     if(moverRect.x <= 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// // fly() is overrided from the superclass
// void Plane::fly(){
//     if (srcRect.x == 307) {
//         srcRect.x=594;
//         srcRect.y=92;
//         srcRect.w=239;
//         srcRect.h=88;

//     } else if (srcRect.x == 594) {
//         srcRect.x=888;
//         srcRect.y=92;
//         srcRect.w=239;
//         srcRect.h=88;

//     } else if (srcRect.x == 888){
//         srcRect.x=307;
//         srcRect.y=92;
//         srcRect.w=240;
//         srcRect.h=86;
//     }

//     moverRect.x -= speed+rand()%10; 

// }
// //// 
// // int Plane::getMoverRectX() const {
// //     return moverRect.x;
// // }

// // int Plane::getMoverRectY() const {
// //     return moverRect.y;
// // }

