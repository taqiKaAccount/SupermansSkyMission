#pragma once
#include "objectCreator.hpp"


Unit* ObjectCreator::getObjectwalking(int x, int y) {
    int n = rand() % 2;
    Unit* objects = nullptr;

    switch (n) {
        case 0:
            objects = new ShootingEnemy(x, y);  //, bulletMaker);
            break;
        case 1:
            objects = new RunningEnemy(x, y);
            break;
    }

    return objects;
}
Unit* ObjectCreator::getObjectflying(int x, int y){
    int n = rand() % 2;
    Unit* objects = nullptr;

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