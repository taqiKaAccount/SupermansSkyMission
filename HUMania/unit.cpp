#include "unit.hpp"


Unit::Unit(){};

void Unit::fly(){};

// Drawing object

void Unit::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

bool Unit::delete_Sprite(){
    return false;
}
