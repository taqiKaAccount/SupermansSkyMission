#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "unit.hpp"

class Plane : public Unit {
public:
    Plane(int x, int y);
    void fly() override; // Override the fly function
    bool del_child();

private:
    int speed = 2;  // Adjusted the speed
    bool flying_up = false;  // Added a new member variable
};
