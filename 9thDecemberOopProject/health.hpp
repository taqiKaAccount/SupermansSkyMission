#pragma once
#include "unit.hpp"
#include "drawing.hpp"


class health{

int life = 3;

public:
int getLife();
// void draw(SDL_Renderer* gRenderer, SDL_Texture* assets);
void reduceHealth(bool DidCollisionOccur) ; 
};