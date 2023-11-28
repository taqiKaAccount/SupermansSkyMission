#include <SDL.h>


class superman
{
public:
    superman(SDL_Renderer *rend, SDL_Texture *ast);

    void draw();


    void fire(SDL_Renderer *rend, SDL_Texture *ast);

    void movement(char direction) ;

    int life_status();
    
    ~superman();
};