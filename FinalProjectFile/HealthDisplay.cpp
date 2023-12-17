#include "HealthDisplay.hpp"

// Constructor for the HealthDisplay class
HealthDisplay::HealthDisplay() {
    // Set initial values for the source and mover rectangles
    srcRect.x = 667;
    srcRect.y = 429;
    srcRect.w = 186;
    srcRect.h = 53;
    
    moverRect.x = 2;
    moverRect.y = 10;
    moverRect.w = 75;
    moverRect.h = 75;
}

// Function to redraw hearts based on the number of hearts left
void HealthDisplay::RedrawHearts(SDL_Renderer* gRenderer, SDL_Texture* assets, int heartsLeft) {
    int n = heartsLeft;

    // Adjust the source rectangle based on the number of hearts left
    switch (n) {
        case 1:
            srcRect = {664, 272, 62, 53};
            moverRect.w = 75;
            break;
        case 2:
            srcRect = {664, 352, 124, 53};
            moverRect.w = 150;
            break;
        case 3:
            srcRect = {667, 429, 186, 53};
            moverRect.w = 225;
            break;
    }

    // Render the hearts on the screen
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
