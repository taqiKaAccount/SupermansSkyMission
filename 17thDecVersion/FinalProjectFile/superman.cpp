#include "superman.hpp" 
// Superman.cpp
#include "unit.hpp"  // Make sure to include the Unit class or define the necessary structs here

Superman::Superman(int x, int y) : srcRect{10, 26, 187, 119}, moverRect{x, y, 75, 75}{}


int Superman::getMoverRectX() const {
    return moverRect.x;
}

int Superman::getMoverRectY() const {
    return moverRect.y;
}

void Superman::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    
    srcRect.x = 10;
    srcRect.y = 26;
    srcRect.w = 187;
    srcRect.h = 119;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::up(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.y <= 0) {
        moverRect.y = 30;
    }
    moverRect.y -= 40;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::down(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.y >= 450) {
        moverRect.y = 400;
    }
    moverRect.y += 40;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::left(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.x <= 0) {
        moverRect.x = 35;
    }
    moverRect.x -= 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::right(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.x >= 900) {
        moverRect.x = 849;
    }
    moverRect.x += 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::createObject(int x, int y) {
    // Implementation as per your requirement
}



void Superman::animation(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (srcRect.x==10){
        srcRect.x = 332;
        srcRect.y = 269;
        srcRect.w = 187;
        srcRect.h = 119;
    }
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    
 }



