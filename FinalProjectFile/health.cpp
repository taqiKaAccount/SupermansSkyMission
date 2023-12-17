#pragma once
#include <iostream>
#include "health.hpp"

// Getter function to retrieve current life value
int health::getLife() {
    return life;
}

// Function to reduce Superman's health based on collision occurrence
void health::reduceHealth(bool DidCollisionOccur) {
    if (DidCollisionOccur) {
        life = life - 1;
    }
}

// Function to test Superman's health and perform actions accordingly
void health::testHealth() {
    // Uncomment the following line if you want to print Superman's current life to the console
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
