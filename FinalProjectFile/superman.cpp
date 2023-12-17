#include "superman.hpp" 
// Superman.cpp
#include "unit.hpp"  // Make sure to include the Unit class or define the necessary structs here

// Constructor for Superman class
Superman::Superman(int x, int y) : srcRect{10, 26, 187, 119}, moverRect{x, y, 75, 75} {}

// Getter function for the x-coordinate of the moverRect
int Superman::getMoverRectX() const {
    return moverRect.x;
}

// Getter function for the y-coordinate of the moverRect
int Superman::getMoverRectY() const {
    return moverRect.y;
}

// Draw function to render Superman on the screen
void Superman::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    // Set the source rectangle coordinates and dimensions
    srcRect.x = 10;
    srcRect.y = 26;
    srcRect.w = 187;
    srcRect.h = 119;

    // Render Superman on the screen
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

// Move Superman up
void Superman::up(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    // Check if Superman is already at the top
    if (moverRect.y <= 0) {
        moverRect.y = 30;
    }
    // Move Superman upward
    moverRect.y -= 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

// Move Superman down
void Superman::down(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    // Check if Superman is already at the bottom
    if (moverRect.y >= 450) {
        moverRect.y = 400;
    }
    // Move Superman downward
    moverRect.y += 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

// Move Superman left
void Superman::left(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    // Check if Superman is already at the left edge
    if (moverRect.x <= 0) {
        moverRect.x = 35;
    }
    // Move Superman to the left
    moverRect.x -= 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

// Move Superman right
void Superman::right(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    // Check if Superman is already at the right edge
    if (moverRect.x >= 900) {
        moverRect.x = 849;
    }
    // Move Superman to the right
    moverRect.x += 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

// Function to create an object as per your requirement
void Superman::createObject(int x, int y) {
    // Implementation as per your requirement
}

// Animation function to change Superman's appearance for a specific action
void Superman::animation(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    // Check if the source rectangle is at the initial position
    if (srcRect.x == 10) {
        // Update source rectangle for the animation
        srcRect.x = 332;
        srcRect.y = 269;
        srcRect.w = 187;
        srcRect.h = 119;
    }
    // Render Superman with updated source rectangle for animation
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
