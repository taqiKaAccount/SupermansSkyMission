#pragma once
#include <iostream>
#include <typeinfo>
#include <iterator>
#include "HUMania.hpp"
using namespace std;

// this function may need to be called in a different manner to check for collisions

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
            
            cout << "Enemy has been deleted" << endl;
            
            //move the iterator one step back to correctly loop through the vector
            //because an element has been erased
            f--;
        }
    }
}


// creates new objects
// int x and y don't do anything, these have to be removed later
//enemy spawning locations are built into their individual classes themselves
void HUMania::createObject(int x, int y){

    ObjectCreator obj;

    Unit *flying_object = obj.getObject(x, y);
    
    flyers.push_back(flying_object);
}


//leave as is
void HUMania::removeObject(Unit*){
    for(Unit *d: flyers){
        delete d;
    }
    flyers.clear();
}
