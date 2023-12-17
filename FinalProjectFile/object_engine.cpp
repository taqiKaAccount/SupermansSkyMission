#pragma once
#include <iostream>
#include <typeinfo>
#include <iterator>
#include "object_engine.hpp"
using namespace std;

// Function to draw and manage flyers in the flyers vector
void object_engine::drawObjects(int timestop) {
    // Loop through the 'flyers' vector
    for (int f = 0; f < flyers.size(); f++) {
        // Draw current flyer
        flyers[f]->draw();

        // Make current flyer perform a flying action if timestop is not active
        if (timestop == 0) {
            flyers[f]->fly();
        }

        // Check if current flyer should be deleted
        if (flyers[f]->del_child() == true) {
            // If it needs to be deleted:

            // Deallocate memory for flyer object
            delete flyers[f];

            // Erase the flyer from the vector
            flyers.erase(flyers.begin() + f);

            cout << "Bee has been deleted" << endl;

            // Move the iterator one step back to correctly loop through the vector
            // because an element has been erased
            f--;
        }
    }
}

// Function to create a new flying object and add it to the flyers vector
void object_engine::createObjectflying(int x, int y) {
    ObjectCreator obj;
    Unit *flying_object = obj.getObjectflying(x, y);
    flyers.push_back(flying_object);
}

// Function to create a new walking object and add it to the flyers vector
void object_engine::createObjectwalking(int x, int y) {
    ObjectCreator obj;
    Unit *walking_object = obj.getObjectwalking(x, y);
    flyers.push_back(walking_object);
}

// Function to remove all objects in the flyers vector
void object_engine::removeObject(Unit*) {
    for (Unit *d : flyers) {
        delete d;
    }
    flyers.clear();
}

// Function to check for collisions between Superman and flyers
bool object_engine::checkSupermanCollision(Superman& superman) {
    SDL_Rect supermanRect = {superman.getMoverRectX(), superman.getMoverRectY(), 75, 75};

    for (size_t i = 0; i < flyers.size(); ++i) {
        Unit* flyer = flyers[i];
        SDL_Rect flyerRect = {flyer->getMoverRectX(), flyer->getMoverRectY(), flyer->getMoverRectW(), flyer->getMoverRectH()};

        if (SDL_HasIntersection(&supermanRect, &flyerRect) == SDL_TRUE) {
            delete flyers[i];
            flyers.erase(flyers.begin() + i);
            cout << "Collision with flyer has been detected" << endl;
            i--; // Move the iterator one step back to correctly loop through the vector
            return true;
        }
    }
    return false;
}

// Function to check for collisions between lazers and flyers
bool object_engine::checkLazerCollision(vector<Unit*> lazersTracker) {
    for (size_t j = 0; j < lazersTracker.size(); j++) {
        Unit* thisLazer = lazersTracker[j];
        SDL_Rect lazerRect = {thisLazer->getMoverRectX(), thisLazer->getMoverRectY(), thisLazer->getMoverRectW(), thisLazer->getMoverRectH()};

        for (size_t i = 0; i < flyers.size(); ++i) {
            Unit* flyer = flyers[i];
            SDL_Rect flyerRect = {flyer->getMoverRectX(), flyer->getMoverRectY(), flyer->getMoverRectW(), flyer->getMoverRectH()};

            if (SDL_HasIntersection(&lazerRect, &flyerRect) == SDL_TRUE) {
                delete flyers[i];
                flyers.erase(flyers.begin() + i);
                cout << "Lazer has been detected" << endl;
                i--; // Move the iterator one step back to correctly loop through the vector
                return true;
            }
        }
    }
    return false;
}

object_engine::~object_engine() {
    // Remove and delete all objects in the flyers vector
    removeObject(nullptr);
}