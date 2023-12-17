#pragma once
#include "objectCreator.hpp"

// Function to create a walking object based on random selection
Unit* ObjectCreator::getObjectwalking(int x, int y) {
    int n = rand() % 6;
    Unit* objects = nullptr;

    // Select a random walking object type
    switch (n) {
        case 0:
            objects = new DoomsDay(x, y);  //, bulletMaker);
            break;
        case 1:
            objects = new RunningEnemy(x, y);
            break;
        case 2:
            objects = new RunningEnemy(x, y);
            break;
        case 3:
            objects = new RunningEnemy(x, y);
            break;
        case 4:
            objects = new RunningEnemy(x, y);
            break;
        case 5:
            objects = new RunningEnemy(x, y);
            break;
    }

    return objects;
}

// Function to create a flying object based on random selection
Unit* ObjectCreator::getObjectflying(int x, int y) {
    int n = rand() % 2;
    Unit* objects = nullptr;

    // Select a random flying object type
    switch (n) {
        case 0:
            objects = new blimp(x, y);
            break;
        case 1:
            objects = new Plane(x, y);
            break;
    }

    return objects;
}
