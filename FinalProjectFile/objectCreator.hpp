#pragma once
#include "Unit.hpp"
#include "Plane.hpp"
#include "RunningEnemy.hpp"
#include "DoomsDay.hpp"
#include "blimp.hpp"


class ObjectCreator {
public:
    Unit* getObjectwalking(int x, int y);
    Unit* getObjectflying(int x, int y);
};