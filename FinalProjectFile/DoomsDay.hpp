#pragma once
#include "unit.hpp"

class DoomsDay : public Unit {
private:
    Uint32 stopTime;    // Time when the enemy should stop
    bool isStopping;    // Flag indicating whether the enemy is stopping
    bool hasStopped;    // Flag indicating whether the enemy has stopped
    
    
public:
    DoomsDay(int x, int y);
    bool del_child();
    void fly();
};