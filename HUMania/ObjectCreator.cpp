// Prevents multiple inclusions of the same header file
#pragma once

// Include the header file for the ObjectCreator class
#include "objectCreator.hpp"

// Method to create and return a pointer to a randomly chosen Unit object
Unit* ObjectCreator::getObject(int x, int y) {
    // Generate a random number between 0 and 2
    int n = rand() % 3;

    // Declare a pointer to a Unit object and initialize it to nullptr
    Unit* animals = nullptr;

    // Use a switch statement to create a specific type of Unit based on the random number
    switch (n) {
        case 0:
            animals = new Bee(x, y);  // Create a Bee object
            break;
        case 1:
            animals = new Butterfly(x, y);  // Create a Butterfly object
            break;
        case 2:
            animals = new Pigeon(x, y);  // Create a Pigeon object
            break;
    }

    // Return the pointer to the created Unit object
    return animals;
}
