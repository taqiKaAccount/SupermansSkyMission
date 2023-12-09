#pragma once
#include "objectCreator.hpp"
Unit* ObjectCreator::getObjectwalking(int x, int y){
    int n = rand() % 2;
    Unit* animals = nullptr;

    switch (n) {
        case 0:
            animals = new ShootingEnemy(x, y);
            break;
        case 1:
            animals = new RunningEnemy(x, y);
            break;
    }
    
    return animals;

}
Unit* ObjectCreator::getObjectflying(int x, int y){
    int n = rand() % 2;
    Unit* animals = nullptr;

    switch (n) {
        case 0:
            animals = new blimp(x, y);
            break;
        case 1:
            animals = new Plane(x, y);
            break;
    }
    
    return animals;

}