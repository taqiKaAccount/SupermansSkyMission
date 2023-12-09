#pragma once
#include "health.hpp"

int health::getLife() {
    return life ;
};

void health::reduceHealth() {
    life = life -1;
    
}

// void health::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){




// }