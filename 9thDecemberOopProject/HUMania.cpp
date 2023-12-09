#pragma once
#include <iostream>
#include <typeinfo>
#include <iterator>
#include "HUMania.hpp"
using namespace std;

//this function doesn't need to be touched at all
void HUMania::drawObjects() {
    //Loop through the 'flyers' vector
    for (int f = 0; f < flyers.size(); f++) {
        //draw current flyer
        flyers[f]->draw();
        
        //make current flyer perform a flying action
        flyers[f]->fly();

        //check if current flyer should be deleted
        if (flyers[f]->del_child() == true) {
            //if it needs to be deleted:
            
            //deallocate memory for flyer object
            delete flyers[f];
            
            //erase the flyer from the vector
            flyers.erase(flyers.begin() + f);
            
            cout << "Bee has been deleted" << endl;
            
            //move the iterator one step back to correctly loop through the vector
            //because an element has been erased
            f--;
        }
    }
}


// creates new objects
// this here specifies where exactly the object would spawn, this should be set according
//  to our exact needs rather than mouse click, which is already implemented in the other file
void HUMania::createObjectflying(int x, int y){
    // std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    ObjectCreator obj;
    
    Unit *flying_object = obj.getObjectflying(x, y);
    flyers.push_back(flying_object);
    
}


// Modify the createObjectflying function to check for collisions
// void HUMania::createObjectflying(int x, int y) {
//     ObjectCreator obj;

//     // Create a flying object
//     Unit* flying_object = obj.getObjectflying(x, y);

//     // Check for collisions with existing objects
//     for (size_t i = 0; i < flyers.size(); ++i) {
//         Unit* existingObject = flyers[i];
//         SDL_Rect newObjectRect = {flying_object->getMoverRectX(), flying_object->getMoverRectY(), flying_object->getMoverRectW(), flying_object->getMoverRectH()};
//         SDL_Rect existingObjectRect = {existingObject->getMoverRectX(), existingObject->getMoverRectY(), existingObject->getMoverRectW(), existingObject->getMoverRectH()};

//         // If a collision is detected, don't add the new object and return
//         if (checkCollision(newObjectRect, existingObjectRect)) {
//             delete flying_object;  // Don't forget to free the memory
//             cout << "Collision detected, flying object not created" << endl;
//             return;
//         }
//     }

//     // No collision detected, add the new object to the vector
//     flyers.push_back(flying_object);
// }



void HUMania::createObjectwalking(int x, int y){
    // std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;


    ObjectCreator obj;
    
    Unit *flying_object = obj.getObjectwalking(x, y);
    flyers.push_back(flying_object);
    

    
}

//leave as is
void HUMania::removeObject(Unit*){
    for(Unit *d: flyers){
        delete d;
    }
    flyers.clear();
}


// so idea is to traverse through the vector and at each moment
// compare the sdl rect of superman with the current vector object via pointers
// if they objects overlap, call the removeObject function and return true
// return true is so that we can change the health of superman using this as a condition

bool HUMania::checkSupermanCollision(Superman& superman)
{
    SDL_Rect supermanRect = {superman.getMoverRectX(), superman.getMoverRectY(), 75, 75};
    
    
    for (size_t i = 0; i < flyers.size(); ++i) {
        Unit* flyer = flyers[i];
        SDL_Rect FlyerRect = {flyer->getMoverRectX(), flyer->getMoverRectY(), flyer->getMoverRectW(), flyer->getMoverRectH()};

        if (SDL_HasIntersection(&supermanRect, &FlyerRect) == SDL_TRUE) {
            delete flyers[i];
            flyers.erase(flyers.begin() + i);
            cout << "collision has been detected" << endl;
            i--;
            return true;
            
        }
        //SDL_HasIntersection is a builtin function which checks for collisions of 2 sdl images
        //rest of the code is essentially looping through our flyers array
        //and comparing with superman image
    }
    return false;
}

bool HUMania::checkLazerCollision(vector<Unit*> lazersTracker){
    SDL_Rect supermanRect = {superman.getMoverRectX(), superman.getMoverRectY(), 75, 75};
    
    for (size_t j = 0; j < lazersTracker.size(); j++)
    {
        Unit* thisLazer = lazersTracker[i];
         SDL_Rect LazerRect = {thisLazer->getMoverRectX(), thisLazer->getMoverRectY(), thisLazer->getMoverRectW(), thisLazer->getMoverRectH()};

        for (size_t i = 0; i < flyers.size(); ++i) 
        {
            Unit* flyer = flyers[i];
            SDL_Rect FlyerRect = {flyer->getMoverRectX(), flyer->getMoverRectY(), flyer->getMoverRectW(), flyer->getMoverRectH()};

            if (SDL_HasIntersection(&LazerRect, &FlyerRect) == SDL_TRUE) {
                delete flyers[i];
                flyers.erase(flyers.begin() + i);
                cout << "Lazer has Been" << endl;
                i--;
                return true;
                
            }
        }
    }
    return false;
};