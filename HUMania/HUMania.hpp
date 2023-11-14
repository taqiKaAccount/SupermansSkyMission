#include<SDL.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void up(SDL_Renderer* gRnderer, SDL_Texture* assets);
void left(SDL_Renderer* gRnderer, SDL_Texture* assets);
void down(SDL_Renderer* gRnderer, SDL_Texture* assets);
void animation(SDL_Renderer* gRnderer, SDL_Texture* assets);


void createObject(int x, int y);



void moveRight();
void moveLeft();
void moveUp();
void moveDown() ;





struct Unit{
SDL_Rect srcRect, moverRect;
};