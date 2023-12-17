#include "SDL.h"
#include "drawing.hpp"
#pragma once
class Unit{
    protected:
    SDL_Rect srcRect, moverRect;
    public:
    void draw();
    virtual void fly(); // making fly() virtual because fly is different for each animal
    Unit();
    virtual bool del_child();

    int getMoverRectX() const;
    int getMoverRectY() const;
    int getMoverRectW() const;
    int getMoverRectH() const;
    
};

