#pragma once
#include <iostream>
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

// void health::healthcheck(){
//     // int life = SupermanHealth.getLife();
//     // SupermanHealth.reduceHealth(true);
//     life.reduceHealth(false);
// }
// int health::healthleft(){
//     healthcheck();
//     life.getLife();
// }
//just to check if health is working
void health::testHealth() {
    // Access health-related functions
    // healthcheck();
    // int life = getLife();
    std::cout << "Superman's current life: " << life << "\n";

    // Perform some actions based on health
    if (life <= 0) {
        std::cout << "Superman is defeated!" << "\n";
        // Perform additional actions when Superman is defeated
    } else {
        std::cout << "Superman is still fighting!" << "\n";
        // Perform additional actions when Superman is still alive
    }
}







// void health::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){




// }
// this will be edited to show hearts on the screen
// based on the life of superman
// update the src rect or something idk