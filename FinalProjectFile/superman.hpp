#ifndef SUPERMAN_HPP
#define SUPERMAN_HPP

#include <SDL.h>
#include <vector>
#include <iostream>
#include "health.hpp"
class Superman{
public:
    Superman(int x, int y);
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void up(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void down(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void left(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void right(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void createObject(int x, int y);
    void animation(SDL_Renderer* gRenderer, SDL_Texture* assets);
    int getMoverRectX() const;
    int getMoverRectY() const;

private:
    SDL_Rect srcRect;
    SDL_Rect moverRect;

};

#endif // SUPERMAN_HPP
