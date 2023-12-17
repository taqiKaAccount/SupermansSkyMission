#pragma once
#include "unit.hpp"
#include "drawing.hpp"


class health{

int life = 3;

public:
int getLife();
void reduceHealth(bool DidCollisionOccur) ;

void testHealth();


};