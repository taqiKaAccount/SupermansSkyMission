#include <SDL.h>
#include <vector>
#include <iostream>
#include "health.hpp"

class HealthDisplay{
    private:
    SDL_Rect srcRect;
    SDL_Rect moverRect;


    public:

    HealthDisplay();

    void RedrawHearts(SDL_Renderer* gRenderer, SDL_Texture* assets ,int heartsleft) ;

  


};