#pragma once
#include "unit.hpp"
#include "drawing.hpp"
#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "drawing.hpp"

class Score {
public:
    Score();
    Score& operator++();    // Prefix increment operator
    Score operator++(int);  // Postfix increment operator
    Score& operator--();    // Prefix decrement operator
    Score operator--(int);  // Postfix decrement operator
    int getScore() const;
    void draw(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer,int x,int y,int w,int h);
    ~Score();
private:
    int ScoreCount;
    SDL_Texture* ftexture;
    int t_width;
    int t_height;
};