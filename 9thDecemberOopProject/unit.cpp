#include "unit.hpp"
Unit::Unit(){};
void Unit::fly(){};
// Drawing object
void Unit::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

bool Unit::del_child(){
    return false;
}

int Unit::getMoverRectX() const {
    return moverRect.x;
}

int Unit::getMoverRectY() const {
    return moverRect.y;
}

int Unit::getMoverRectW() const {
    return moverRect.w;
}

int Unit::getMoverRectH() const {
    return moverRect.h;
}