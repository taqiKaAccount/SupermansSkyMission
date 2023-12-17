#include "DoomsDay.hpp"

DoomsDay:: DoomsDay(int x, int y): Unit(), stopTime(0), isStopping(false), hasStopped(false) {
    Unit::srcRect = {696, 551,159,176};
    Unit::moverRect = {20, 500, 100, 100};
}

bool DoomsDay::del_child() {
    if (moverRect.x >= 999) {
        return true;
    } else {
        return false;
    }
}

void DoomsDay::fly() {
    // If the enemy is stopping and hasn't stopped yet
    
    static bool isJumping = false;
    static Uint32 stopTime = 0;
    static Uint32 jumpStartTime = 0;

    if (isStopping && !hasStopped) {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - stopTime >= 500) {  // Stop for 2000 milliseconds (adjust as needed)
            isStopping = false;
            hasStopped = true;  // Set the flag to indicate that the enemy has stopped
            jumpStartTime = SDL_GetTicks();
            isJumping = true;
            moverRect.y += 150;
        }
    } else {
        // Continue flying
        moverRect.x += 15;

        // Check if the enemy should stop
        if (!isStopping && !hasStopped && moverRect.x >= rand() % 500 + 300) {
            if (srcRect.x == 696 or srcRect.x == 1132 ) {
                srcRect.x = 1126; 
                srcRect.y = 760;
                srcRect.w = 156;
                srcRect.h = 183;
            }
            isJumping = false;
            isStopping = true;
            stopTime = SDL_GetTicks(); 
            moverRect.y -= 150;
            

        }
        if (srcRect.x == 1132 ) {
                srcRect.x = 696;
                srcRect.y = 551;
                srcRect.w = 159;
                srcRect.h = 155;
            }
        else if (srcRect.x==696){
                srcRect.x = 1132;
                srcRect.y = 546;
                srcRect.w = 156;
                srcRect.h = 183;
        }
        else if(srcRect.x == 1126 and isJumping == true){
                srcRect.x = 696;
                srcRect.y = 551;
                srcRect.w = 159;
                srcRect.h = 155;
        }
        
        // Reset jump-related flags when landing
        if (moverRect.y >= 600 - 50) {
            moverRect.y = 600 - 50;
            hasStopped = false;
            isJumping = false;
        }
    }
}
