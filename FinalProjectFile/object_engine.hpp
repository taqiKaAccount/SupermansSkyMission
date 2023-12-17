#pragma once
#include<SDL.h>
#include "Plane.hpp"
#include "unit.hpp"
#include "objectCreator.hpp"
#include "superman.hpp"
#include "DoomsDay.hpp"
#include<vector>
#include<list>
#include<typeinfo>
#include<iterator>
using namespace std;

class object_engine{
    //Create your list here
    vector<Unit*> flyers;
    public:
    void drawObjects(int timestop); 
    void createObjectwalking(int, int);//,BulletMaker *);

    void createObjectflying(int, int);
    void removeObject(Unit*);
    
    // bool checkcollision(Superman superman, Unit* B) ;
    bool checkSupermanCollision(Superman& superman) ;

    bool checkLazerCollision(vector<Unit*> lazersTracker) ;
    //this will take the LazerVector
    //loop through both the vectors
    //if collision it will delete the enemy object only
    //you may hit multiple enemies with a single lazer
    ~object_engine();
};

//object_engine will get repurposed as our "Create and remove enemy sprites Class"
//So can rename to EnemyHandler
//can create another vector for this called "walkers"
//that can handle the enemys on the floor

//all that needs to be done is a specified starting positions for each object
//this would give all 4 types of enemies a range in which they would exist
//rather than creating objects on input of mouse