#include "Laser.hpp"
#include <iostream>

#include "superman.hpp"


Laser::Laser(int x, int y) : laserUnit{{257, 24, 173, 134}, {x, y, 75, 75}} {}

const SDL_Rect& Laser::getMoverRect() const {
    return laserUnit.moverRect;
}

void Laser::move() {
    laserUnit.moverRect.y += 75; // Adjust the value based on your preference
}

void Laser::draw(SDL_Renderer* gRenderer, SDL_Texture* assets, Superman superman) {
    // Check if laser has reached the bottom of the screen
    if (laserUnit.moverRect.y >= 999) {
        // No need to delete the laser object explicitly,
        // it will be automatically destructed when the vector is cleared
        return; // Skip rendering and moving
    }

    // Render the laser on the screen
    SDL_RenderCopy(gRenderer, assets, &laserUnit.srcRect, &laserUnit.moverRect);

    // Move the laser down
    move();

    // Iterate through the bees vector for collision detection
    // for (auto it = bees2.begin(); it != bees2.end();) {
    //     Unit& bee = *it; // Get a reference to the current bee

    //     // Check for collision with bee
    //     if (superman.supermanCollision(&laserUnit.moverRect, &bee.moverRect)) {
    //         std::cout << "laser collided with a bee!" << std::endl;
    //         // Add any additional actions you want to perform when a collision occurs

    //         // Store the bee iterator for later removal
    //         it = bees2.erase(it); // Erase the current bee and get the next iterator
    //         continue; // Skip rendering for this iteration
    //     }

    //     ++it; // Move to the next iterator
    // }

    // for (auto it = bees.begin(); it != bees.end();) {
    //     Unit& bee = *it; // Get a reference to the current bee

    //     // Check for collision with bee
    //     if (superman.supermanCollision(&laserUnit.moverRect, &bee.moverRect)) {
    //         std::cout << "laser collided with a bee!" << std::endl;
    //         // Add any additional actions you want to perform when a collision occurs
    //         it = bees.erase(it); // Erase the current bee and get the next iterator
    //         continue; // Skip rendering for this iteration
    //     }

    //     ++it; // Move to the next iterator
    // }
}
