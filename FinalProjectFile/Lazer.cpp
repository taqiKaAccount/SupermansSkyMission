#pragma once
#include "Lazer.hpp"

// Function to check if the lazer should be deleted based on its position
bool Lazer::del_child() {
    // If the lazer has moved beyond the bottom of the screen, return true (indicating it should be deleted)
    if (moverRect.y > 600) {
        return true;
    } else {
        return false;
    }
}

// Constructor for the Lazer class, initializing source and mover rectangles
Lazer::Lazer(int x, int y) : Unit() {
    // Set initial values for source rectangle representing the lazer image
    Unit::srcRect = {71, 286, 98, 165};

    // Set initial values for mover rectangle representing the lazer's position and size
    Unit::moverRect = {x, y, 50, 50};
}

// Function to update the lazer's position (movement)
void Lazer::fly() {
    // Move the lazer down the screen
    moverRect.y += 100;

    // Reset source rectangle values if needed for animation or appearance
    if (srcRect.x == 71) {
        srcRect.x = 71;
        srcRect.y = 286;
        srcRect.w = 98;
        srcRect.h = 165;
    }
}
