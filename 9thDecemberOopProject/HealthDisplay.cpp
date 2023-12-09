#include "HealthDisplay.hpp"




//HealthDisplay::HealthDisplay() : srcRect(667, 429, 186, 53), moverRect(2, 10, 75, 75) {}

HealthDisplay::HealthDisplay() {
    srcRect.x = 667;
    srcRect.y = 429;
    srcRect.w = 186;
    srcRect.h = 53;
    moverRect.x = 2;
    moverRect.y = 10;
    moverRect.w = 75;
    moverRect.h = 75;
}

void HealthDisplay::RedrawHearts(SDL_Renderer* gRenderer, SDL_Texture* assets ,int heartsleft){
    int n = heartsleft;
    switch (n)
    {
    case 1:
        srcRect = {664, 272, 62, 53} ;
        moverRect.w = 75;
        break;
    case 2:
        srcRect = {664, 352, 124, 53} ;
        moverRect.w = 150;
        break;
    case 3:
        srcRect= {667, 429, 186, 53} ;
        moverRect.w = 225;
        break;
    }
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect); 
};