#pragma once


#include "HUMania.hpp"
#include "superman.hpp"
class Superman; 
class Laser {
public:
    Laser(int x, int y);
    
    const SDL_Rect& getMoverRect() const;

    void move();

    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets, Superman superman);

private:
    Unit laserUnit;
};
