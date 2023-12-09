#pragma once
#include "health.hpp"

int health::getLife() {
    return life ;
};

void health::reduceHealth(bool DidCollisionOccur) {
    if ( DidCollisionOccur )
    {
        life = life -1;
    }
    
}

// void health::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){




// }
// this will be edited to show hearts on the screen
// based on the life of superman
// update the src rect or something idk