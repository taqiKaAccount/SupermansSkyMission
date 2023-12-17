// ShootingEnemy.hpp
#pragma once
#include "unit.hpp"
// #include "BulletMaker.hpp"
class ShootingEnemy : public Unit {
private:
    Uint32 stopTime;    // Time when the enemy should stop
    bool isStopping;    // Flag indicating whether the enemy is stopping
    bool hasStopped;    // Flag indicating whether the enemy has stopped
    // Add a BulletMaker member variable to ShootingEnemy
    
public:
    ShootingEnemy(int x, int y);//,BulletMaker *bulletMaker);
    bool del_child();
    void fly();
};