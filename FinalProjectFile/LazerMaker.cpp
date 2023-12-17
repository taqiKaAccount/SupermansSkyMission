#pragma once
#include <iostream>
#include <typeinfo>
#include <iterator>
#include "LazerMaker.hpp"
using namespace std;

// Function to draw and manage lazers in the lazerVector
void LazerMaker::drawObjects() {
    // Loop through the 'lazerVector'
    // if (lazerVector.size() < 5) { // Uncomment this condition if you want to limit the number of lazers on the screen
    for (int f = 0; f < lazerVector.size(); f++) {
        // Draw current lazer
        lazerVector[f]->draw();

        // Make current lazer perform a flying action
        lazerVector[f]->fly();

        // Check if current lazer should be deleted
        if (lazerVector[f]->del_child() == true) {
            // If it needs to be deleted:

            // Deallocate memory for lazer object
            delete lazerVector[f];

            // Erase the lazer from the vector
            lazerVector.erase(lazerVector.begin() + f);

            cout << "Lazer has been deleted" << endl;

            // Move the iterator one step back to correctly loop through the vector
            // because an element has been erased
            f--;
        }
    }
    // }
}

// Function to create a new lazer object and add it to the lazerVector
void LazerMaker::createObject(int x, int y) {
    if (lazerVector.size() < 1) { // Uncomment this condition if you want to limit the number of lazers on the screen
        Unit *flying_object = new Lazer(x, y);
        lazerVector.push_back(flying_object);
    }
}

// Function to remove all objects in the lazerVector
void LazerMaker::removeObject(Unit*) {
    for (Unit *d : lazerVector) {
        delete d;
    }
    lazerVector.clear();
}

// Function to return the lazerVector
vector<Unit*> LazerMaker::returnLazerVector() {
    return lazerVector;
}

LazerMaker::~LazerMaker() {
    // Remove and delete all objects in the lazerVector
    removeObject(nullptr);
}