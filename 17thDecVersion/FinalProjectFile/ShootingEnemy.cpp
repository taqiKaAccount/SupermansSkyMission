#include "ShootingEnemy.hpp"

ShootingEnemy::ShootingEnemy(int x, int y) : Unit(), stopTime(0), isStopping(false), hasStopped(false) {
    // Unit::srcRect = {1383, 843, 94, 129};
    Unit::srcRect = {1383, 900, 150, 250};

    Unit::moverRect = {20, 550, 50, 50};
}

bool ShootingEnemy::del_child() {
    if (moverRect.x >= 999) {
        return true;
    } else {
        return false;
    }
}

// Modify the constructor to take a BulletMaker pointer
// ShootingEnemy::ShootingEnemy(int x, int y, BulletMaker* bulletMakerPtr)
//     : Unit(), stopTime(0), isStopping(false), hasStopped(false), bulletMaker(bulletMakerPtr) {
//     Unit::srcRect = {1383, 843, 94, 129};
//     Unit::moverRect = {20, 550, 50, 50};
// }
void ShootingEnemy::fly() {
    // If the enemy is stopping and hasn't stopped yet
    if (isStopping && !hasStopped) {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - stopTime >= 2000) {  // Stop for 2000 milliseconds (adjust as needed)
            isStopping = false;
            hasStopped = true;  // Set the flag to indicate that the enemy has stopped
        }
    } else {
        // Continue flying
        moverRect.x += 15;

        // Check if the enemy should stop
        if (!isStopping && !hasStopped && moverRect.x >= rand() % 500 + 300) {
            if (srcRect.x == 724 or srcRect.x == 1383 ) {
            srcRect.x = 41; 
            srcRect.y = 818;
            srcRect.w = 77;
            srcRect.h = 155;
            }
            isStopping = true;
            stopTime = SDL_GetTicks(); 
             // Record the time when stopping
            // bulletMaker->createObject(moverRect.x, moverRect.y);
        }

        // Update animation frames
        else if (srcRect.x == 724) {
            srcRect.x = 1383;
            srcRect.y = 843;
            srcRect.w = 94;
            srcRect.h = 129;
        } else if (srcRect.x == 1383) {
            srcRect.x = 41; 
            srcRect.y = 818;
            srcRect.w = 77;
            srcRect.h = 155;
        }
        else if (srcRect.x == 41){
            srcRect.x = 724; 
            srcRect.y = 843;
            srcRect.w = 95;
            srcRect.h = 129;
        }
    }
}