#pragma once
#include <iostream>
#include <typeinfo>
#include <iterator>
#include "BulletMaker.hpp"
using namespace std;

void BulletMaker::drawObjects() {
    //Loop through the 'flyers' vector
    for (int f = 0; f < BulletVector.size(); f++) {
        //draw current flyer
        BulletVector[f]->draw();
        
        //make current flyer perform a flying action
        BulletVector[f]->fly();

        //check if current flyer should be deleted
        if (BulletVector[f]->del_child() == true) {
            //if it needs to be deleted:
            
            //deallocate memory for flyer object
            delete BulletVector[f];
            
            //erase the flyer from the vector
            BulletVector.erase(BulletVector.begin() + f);
            
            cout << "Bullet has been deleted" << endl;
            
            //move the iterator one step back to correctly loop through the vector
            //because an element has been erased
            f--;
        }
    }
}


void BulletMaker::createObject(int x, int y){
    Unit *flying_object = new bullet(x, y);
    BulletVector.push_back(flying_object);
}


//leave as is
void BulletMaker::removeObject(Unit*){
    for(Unit *d: BulletVector){
        delete d;
    }
    BulletVector.clear();
}

vector<Unit*> BulletMaker::returnBulletVector()
{
    return BulletVector ;
};