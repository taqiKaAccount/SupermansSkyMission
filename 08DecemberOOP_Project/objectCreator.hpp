#pragma once
#include "Unit.hpp"
#include "Plane.hpp"
#include "bee.hpp"
#include "butterfly.hpp"

class ObjectCreator{
    public:
        Unit* getObject(int x, int y);
};