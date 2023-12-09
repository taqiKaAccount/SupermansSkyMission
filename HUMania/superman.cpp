#include "superman.hpp" 
// Superman.cpp
#include "unit.hpp"  // Make sure to include the Unit class or define the necessary structs here

#include "laser.hpp"

Superman::Superman(int x, int y) : srcRect{7, 88, 155, 103}, moverRect{x, y, 75, 75} {}

const SDL_Rect& Superman::getMoverRect() const {
    return moverRect; // Assuming moverRect is a member variable in the Superman class
}

void Superman::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    srcRect.x = 0;
    srcRect.y = 237;
    srcRect.w = 153;
    srcRect.h = 84;
}

void Superman::up(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.y <= 0) {
        moverRect.y = 30;
    }
    moverRect.y -= 15;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::down(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.y >= 450) {
        moverRect.y = 400;
    }
    moverRect.y += 15;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::left(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.x <= 0) {
        moverRect.x = 20;
    }
    moverRect.x -= 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::right(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    if (moverRect.x <= 0) {
        moverRect.x = 20;
    }
    moverRect.x += 50;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Superman::createObject(int x, int y) {
    // Implementation as per your requirement
    
}

bool Superman::supermanCollision(const SDL_Rect* A, SDL_Rect* B) {
    SDL_bool collided = SDL_HasIntersection(A, B);
    return collided == SDL_TRUE;
}

void Superman::animation(SDL_Renderer* gRenderer, SDL_Texture* assets,std::vector<Laser>& lasers) {
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    // srcRect.x = 2;
    // srcRect.y = 361;
    // srcRect.w = 159;
    // srcRect.h = 124;
    srcRect.x = 332;
    srcRect.y = 269;
    srcRect.w = 187;
    srcRect.h = 119;
    lasers.push_back(Laser(moverRect.x, moverRect.y));
    
}
/// health working
void Superman::decreaseHealth(){
    health-=1;
}
