#include<SDL.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void up(SDL_Renderer* gRnderer, SDL_Texture* assets);
void left(SDL_Renderer* gRnderer, SDL_Texture* assets);
void down(SDL_Renderer* gRnderer, SDL_Texture* assets);
void animation(SDL_Renderer* gRnderer, SDL_Texture* assets);


void createObject(int x, int y);

void drawObjectswalking(SDL_Renderer* gRnderer, SDL_Texture* assets);
void animation_walking(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject_walking(int x, int y);
void drawObjectswalking2(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject_walking2(int x, int y);


void drawObjectsflying(SDL_Renderer* gRnderer, SDL_Texture* assets);
void animation_flying(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject_flying(int x, int y);


void moveRight();
void moveLeft();
void moveUp();
void moveDown() ;





struct Unit{
SDL_Rect srcRect, moverRect;
};
