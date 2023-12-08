// Superman.hpp

#ifndef SUPERMAN_HPP
#define SUPERMAN_HPP

#include <SDL.h>
#include <vector>
//class Laser; // Forward declaration
class Superman{
public:
    Superman(int x, int y);
    void draw(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void up(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void down(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void left(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void right(SDL_Renderer* gRenderer, SDL_Texture* assets);
    void createObject(int x, int y);
    bool supermanCollision(const SDL_Rect* A, SDL_Rect* B);
    //void animation(SDL_Renderer* gRenderer, SDL_Texture* assets,std::vector<Laser>& lasers);
    const SDL_Rect& getMoverRect() const;

private:
    SDL_Rect srcRect;
    SDL_Rect moverRect;
};

#endif // SUPERMAN_HPP
