// ShootingEnemy.hpp
#pragma once
#include "unit.hpp"

class ShootingEnemy : public Unit {
private:
    Uint32 stopTime;    // Time when the enemy should stop
    bool isStopping;    // Flag indicating whether the enemy is stopping
    bool hasStopped;    // Flag indicating whether the enemy has stopped

public:
    ShootingEnemy(int x, int y);
    bool del_child();
    void fly();
};