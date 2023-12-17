#pragma once
#include "Unit.hpp"
#include "Plane.hpp"
#include "RunningEnemy.hpp"
#include "ShootingEnemy.hpp"
#include "blimp.hpp"


class ObjectCreator {
public:
    Unit* getObjectwalking(int x, int y);//, BulletMaker* bulletMaker);
    Unit* getObjectflying(int x, int y);
};