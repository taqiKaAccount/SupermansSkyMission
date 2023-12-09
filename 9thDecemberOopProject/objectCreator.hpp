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
        Unit* getObjectwalking(int x, int y);
        
        Unit* getObjectflying(int x, int y);
};