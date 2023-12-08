#pragma once
#include <iostream>
#include <typeinfo>
#include <iterator>
#include "HUMania.hpp"
using namespace std;

// void HUMania::drawObjects(){

//     for(int f=0; f<flyers.size(); f++){
        
//         flyers[f]->draw();
        
//         flyers[f]->fly();

//         if(flyers[f]->del_child() == true){
//             delete flyers[f]; 
//             flyers.erase(flyers.begin() + f);
//             cout << "Bee has been deleted"<<endl;
//         }
//     }
// }
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
void HUMania::createObject(int x, int y){
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    ObjectCreator obj;
    Unit *flying_object = obj.getObject(x, y);
    flyers.push_back(flying_object);
}

void HUMania::removeObject(Unit*){
    for(Unit *d: flyers){
        delete d;
    }
    flyers.clear();
}
