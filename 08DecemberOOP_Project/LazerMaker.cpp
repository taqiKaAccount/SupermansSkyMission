#pragma once
#include <iostream>
#include <typeinfo>
#include <iterator>
#include "LazerMaker.hpp"
using namespace std;

void LazerMaker::drawObjects() {
    //Loop through the 'flyers' vector
    for (int f = 0; f < lazerVector.size(); f++) {
        //draw current flyer
        lazerVector[f]->draw();
        
        //make current flyer perform a flying action
        lazerVector[f]->fly();

        //check if current flyer should be deleted
        if (lazerVector[f]->del_child() == true) {
            //if it needs to be deleted:
            
            //deallocate memory for flyer object
            delete lazerVector[f];
            
            //erase the flyer from the vector
            lazerVector.erase(lazerVector.begin() + f);
            
            cout << "Lazer has been deleted" << endl;
            
            //move the iterator one step back to correctly loop through the vector
            //because an element has been erased
            f--;
        }
    }
}


void LazerMaker::createObject(int x, int y){
    Unit *flying_object = new Lazer(x, y);
    lazerVector.push_back(flying_object);
}
// the x and y values are the superman moverrect.x and .y
//so the lazer spanws on supermans location

//leave as is
void LazerMaker::removeObject(Unit*){
    for(Unit *d: lazerVector){
        delete d;
    }
    lazerVector.clear();
}
