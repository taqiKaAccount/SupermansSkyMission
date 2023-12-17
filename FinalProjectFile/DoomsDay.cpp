#include "DoomsDay.hpp"

DoomsDay:: DoomsDay(int x, int y): Unit(), stopTime(0), isStopping(false), hasStopped(false) {
    Unit::srcRect = {696, 551,159,176};
    Unit::moverRect = {20, 500, 100, 100};
}

// bool DoomsDay::del_child() {
//     if (moverRect.x >= 999) {
//      DoomsDay;
//     } else {
//         return false;
//     }
// }
bool DoomsDay::del_child() {
    if (moverRect.x >= 999) {
        return true;
    } else {
        return false;
    }
}
// Modify the constructor to take a BulletMaker pointer
// DoomsDay::DoomsDay(int x, int y, BulletMaker* bulletMakerPtr)
//     : Unit(), stopTime(0), isStopping(false), hasStopped(false), bulletMaker(bulletMakerPtr) {
// DoomsDayReDoomsDay43, 94, 129};
//     Unit::moverRect = {20, 550, 50, 50};
// }
void DoomsDay::fly() {
    // If the enemy is stopping and hasn't stopped yet
    
    static bool isJumping = false;
    static Uint32 stopTime = 0;
    static Uint32 jumpStartTime = 0;

    if (isStopping && !hasStopped) {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - stopTime >= 2000) {  // Stop for 2000 milliseconds (adjust as needed)
            isStopping = false;
            hasStopped = true;  // Set the flag to indicate that the enemy has stopped
            jumpStartTime = SDL_GetTicks();
            isJumping = true;
            moverRect.y += 500;
        }
    } else {
        // Continue flying
        moverRect.x += 15;

        // Check if the enemy should stop
        if (!isStopping && !hasStopped && moverRect.x >= rand() % 500 + 300) {
            if (srcRect.x == 724 or srcRect.x == 1383) {
                srcRect.x = 41; 
                srcRect.y = 818;
                srcRect.w = 77;
                srcRect.h = 155;
            }
            isStopping = true;
            stopTime = SDL_GetTicks(); 
            moverRect.y -= 500;

        }
        

        // Update animation frames
        // ... (your existing animation logic)
        

        // Reset jump-related flags when landing
        if (moverRect.y >= 600 - 50) {
            moverRect.y = 600 - 50;
            hasStopped = false;
            isJumping = false;
        }
    }
}
