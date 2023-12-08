#include "superman.hpp" 
// Superman.cpp
#include "unit.hpp"  // Make sure to include the Unit class or define the necessary structs here


 Superman::Superman(int x, int y) : srcRect{10, 26, 187, 119}, moverRect{x, y, 75, 75} {}
//laser superman coordinates  332,269,187,119

// Superman::Superman(int x, int y) : public Unit() {
//     Unit::srcRect = {7, 88, 155, 103};  // Initialize srcRect with specific values
//     Unit::moverRect = {x, y, 75, 75};
// }

int Superman::getMoverRectX() const {
    return moverRect.x;
}

int Superman::getMoverRectY() const {
    return moverRect.y;
}

void Superman::draw(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    srcRect.x = 10;
    srcRect.y = 26;
    srcRect.w = 187;
    srcRect.h = 119;
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

bool Superman::supermanCollision(const SDL_Rect* A, SDL_Rect* B) {
    SDL_bool collided = SDL_HasIntersection(A, B);
    return collided == SDL_TRUE;
}

// void Superman::animation(SDL_Renderer* gRenderer, SDL_Texture* assets,std::vector<Laser>& lasers) {
//     SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
//     srcRect.x = 2;
//     srcRect.y = 361;
//     srcRect.w = 159;
//     srcRect.h = 124;
//     lasers.push_back(Laser(moverRect.x, moverRect.y));
//}

