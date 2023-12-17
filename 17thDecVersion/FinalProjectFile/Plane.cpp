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
    int n = rand()%2;
        if (n == 0){
    // Adjust the flying logic based on the direction
    int m = rand()%2;
    if (m == 0) {
        moverRect.y -= speed + rand() % 25;
        
        // Change direction when reaching the top half of the screen
        if (moverRect.y <= 0) {
            flying_up = false;
        }
    } else {
        moverRect.y += speed + rand() % 30;
        
        // Change direction when reaching the bottom of the top half
        if (moverRect.y >= 280) {
            flying_up = true;
        }
    }

    moverRect.x -= speed + rand() % 5;
    speed = speed + 0.25 ; 
        }
    else{
                moverRect.x -= speed + 20;
    speed = speed + 0.25 ; }
}


