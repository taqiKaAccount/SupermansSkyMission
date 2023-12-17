#include "Plane.hpp"

// Constructor for the Plane class, initializes source and mover rectangles
Plane::Plane(int x, int y) : Unit() {
    Unit::srcRect = {307, 92, 240, 86};
    Unit::moverRect = {850, 50, 75, 50};
}

// Function to check if the plane should be deleted based on its position
bool Plane::del_child() {
    // Check if the plane has moved off the left side of the screen
    if (moverRect.x <= 0) {
        return true; // Plane should be deleted
    } else {
        return false; // Plane should not be deleted
    }
}

// Function to make the plane fly with animation and random movement
void Plane::fly() {
    // Update animation frames based on the current source rectangle
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

    // Randomly choose flying direction and adjust speed
    int n = rand()%2;
    if (n == 0) {
        // Randomly choose upward or downward movement
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
    } else {
        // Move the plane to the left with increased speed
        moverRect.x -= speed + 20;
        speed = speed + 0.25 ;
    }
}
