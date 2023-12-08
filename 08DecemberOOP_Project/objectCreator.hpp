#pragma once
#include "Unit.hpp"
#include "Plane.hpp"
#include "RunningEnemy.hpp"
#include "ShootingEnemy.hpp"
#include "blimp.hpp"

#include "bee.hpp"
#include "butterfly.hpp"

class ObjectCreator{
    public:
        Unit* getObject(int x, int y);
};