#pragma once
#include "unit.hpp"
#include "drawing.hpp"


class score{

int score = 0;

public:
int getScore();
// void draw(SDL_Renderer* gRenderer, SDL_Texture* assets);
void increaseScore(bool DidCollisionOccur) ; 
};