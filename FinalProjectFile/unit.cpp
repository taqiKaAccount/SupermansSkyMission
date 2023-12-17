#include "unit.hpp"

// Default constructor for the Unit class
Unit::Unit() {}

// Virtual function for the fly action (to be overridden by derived classes)
void Unit::fly() {}

// Drawing function to render the object on the screen
void Unit::draw() {
    // Render the object using SDL_RenderCopy with specified source and mover rectangles
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

// Function to determine if the object should be deleted (to be overridden by derived classes)
bool Unit::del_child() {
    // Default implementation returns false, indicating the object should not be deleted
    return false;
}

// Getter function for the x-coordinate of the moverRect
int Unit::getMoverRectX() const {
    return moverRect.x;
}

// Getter function for the y-coordinate of the moverRect
int Unit::getMoverRectY() const {
    return moverRect.y;
}

// Getter function for the width of the moverRect
int Unit::getMoverRectW() const {
    return moverRect.w;
}

// Getter function for the height of the moverRect
int Unit::getMoverRectH() const {
    return moverRect.h;
}
