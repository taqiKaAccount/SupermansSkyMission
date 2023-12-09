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

    void RedrawHearts(int heartsleft) ;


}