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


void health::testHealth() {
    // std::cout << "Superman's current life: " << life << "\n";

    // Perform some actions based on health
    if (life <= 0) {
        std::cout << "Superman is defeated!" << "\n";
        // Perform additional actions when Superman is defeated
    } else {
        std::cout << "Superman is still fighting!" << "\n";
        // Perform additional actions when Superman is still alive
    }
}


// this will be edited to show hearts on the screen
// based on the life of superman
// update the src rect or something idk