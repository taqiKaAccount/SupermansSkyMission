#pragma once
#include <iostream>
#include "RunningEnemy.hpp"

// Constructor for the RunningEnemy class, initializes source and mover rectangles
RunningEnemy::RunningEnemy(int x, int y) : Unit(){
    Unit::srcRect = {334,588,126,148};
    Unit::moverRect = {850, 490, 150, 100};
}

// Function to check if the running enemy should be deleted based on its position
bool RunningEnemy::del_child(){
    // Check if the running enemy has moved off the left side of the screen
    if(moverRect.x <= 0){
        return true; // Running enemy should be deleted
    }
    else{
        return false; // Running enemy should not be deleted
    }
}

// Function to make the running enemy move horizontally with animation
void RunningEnemy::fly(){
    // Move the running enemy to the left
    moverRect.x -= 15; 

    // Update animation frames based on the current source rectangle
    if (srcRect.x == 334) {
        srcRect.x = 26;
        srcRect.y = 589;
        srcRect.w = 147;
        srcRect.h = 152;
    } else if (srcRect.x == 26) {
        srcRect.x = 334;
        srcRect.y = 588;
        srcRect.w = 126;
        srcRect.h = 148;
    }
}
