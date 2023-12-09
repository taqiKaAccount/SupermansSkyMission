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
// bool HUMania::checkcollision(Superman superman, Unit* B){
//     if (superman.getMoverRectX() == B->getMoverRectX() and superman.getMoverRectY() == B.getMoverRectY())
//     {
//         return true ;
//     }
//     else{return false; }
//     // int hello = A->getMoverRectX();
//     // bool collided = SDL_HasIntersection(A, B);
//     // return collided;
//     // this checks if the rectangles of both the objects are overlapping
//     // if they are return true
// };

void HUMania::checkSupermanCollision(Superman& superman)
{
    SDL_Rect supermanRect = {superman.getMoverRectX(), superman.getMoverRectY(), 75, 75};
    

    // Iterate through the flyers vector and check collisions with Superman
    // for (size_t i = 0; i < flyers.size(); ++i) {
    //     Unit* flyer = flyers[i];
    //     // Unit* flyerRect = {flyer->getMoverRectX(), flyer->getMoverRectY(), flyer->getMoverRectW(), flyer->getMoverRectH()};
    //     // std::cout<<flyerRect.x;
    //     // Unit* flyerRect = flyer;

    //     // Check collision between Superman and the flyer
    //     // if (checkcollision(superman, &flyerRect)) {
    //     //     flyer->del_child();
    //     // }

    //     if (superman.getMoverRectX() == flyer->getMoverRectX() and superman.getMoverRectY() == flyer->getMoverRectY()) {
    //         flyer->del_child();
    //     }
    // }

    std::vector<Point> flyerPositions;
    Point supermanPosition;
    supermanPosition.x = superman.getMoverRectX();
    supermanPosition.y = superman.getMoverRectY();
    for (size_t i = 0; i < flyers.size(); ++i) {
        Unit* flyer = flyers[i];
        Point flyerPosition;
        SDL_Rect FlyerRect = {flyer->getMoverRectX(), flyer->getMoverRectY(), flyer->getMoverRectW(), flyer->getMoverRectH()};
        // flyerPosition.x = flyer->getMoverRectX();
        // flyerPosition.y = flyer->getMoverRectY();
        // flyerPositions.push_back(flyerPosition);
        if (SDL_HasIntersection(&supermanRect, &FlyerRect) == SDL_TRUE) {
            delete flyers[i];
            flyers.erase(flyers.begin() + i);
            cout << "collision has been detected" << endl;
            i--;
            
        }
    
    // for (const auto& position : flyerPositions) {
    //     // if (position.x == supermanPosition.x && position.y == supermanPosition.y) {
    //     //     delete flyers[i];
    //     //     flyers.erase(flyers.begin() + i);
    //     //     cout << "collision has been detected" << endl;
    //     //     i--;
            
    //     // }
        
        
    // }

    }

    // Checking if [superman.getMoverRectX(), superman.getMoverRectY()] exists within flyerPositions
    

    
}