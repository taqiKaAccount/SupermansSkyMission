#pragma once
#include "objectCreator.hpp"
Unit* ObjectCreator::getObject(int x, int y){
    int n = rand() % 4;
    Unit* animals = nullptr;

    switch (n) {
        case 0:
            animals = new ShootingEnemy(x, y);
            break;
        case 1:
            animals = new RunningEnemy(x, y);
            break;
        case 2:
            animals = new blimp(x, y);
            break;
        case 3:
            animals = new Plane(x, y);
            break;
    }
    
    return animals;

}
