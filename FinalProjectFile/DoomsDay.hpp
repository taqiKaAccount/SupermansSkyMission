// DoomsDay.hpp
#pragma once
#include "unit.hpp"
// #include "BulletMaker.hpp"
class DoomsDay : public Unit {
private:
    Uint32 stopTime;    // Time when the enemy should stop
    bool isStopping;    // Flag indicating whether the enemy is stopping
    bool hasStopped;    // Flag indicating whether the enemy has stopped
    // Add a BulletMaker member variable to DoomsDay
    
public:
    DoomsDay(int x, int y);//,BulletMaker *bulletMaker);
    bool del_child();
    void fly();
};