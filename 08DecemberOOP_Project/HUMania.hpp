#pragma once
#include<SDL.h>
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"
#include "unit.hpp"
#include "objectCreator.hpp"
#include<vector>
#include<list>
#include<typeinfo>
#include<iterator>
using namespace std;

class HUMania{
    //Create your list here
    vector<Unit*> flyers;
    public:
    void drawObjects(); 
    void createObject(int, int);
    void removeObject(Unit*);
};

//HuMania will get repurposed as our "Create and remove enemy sprites Class"
//So can rename to EnemyHandler
//can create another vector for this called "walkers"
//that can handle the enemys on the floor

//all that needs to be done is a specified starting positions for each object
//this would give all 4 types of enemies a range in which they would exist
//rather than creating objects on input of mouse