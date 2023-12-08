#pragma once
#include "objectCreator.hpp"
Unit* ObjectCreator::getObject(int x, int y){
    int n = rand() % 3;
    Unit* animals = nullptr;

    switch (n) {
        case 0:
            animals = new Bee(x, y);
            break;
        case 1:
            animals = new Butterfly(x, y);
            break;
        case 2:
            animals = new Plane(x, y);
            break;
    }
    
    return animals;

}
