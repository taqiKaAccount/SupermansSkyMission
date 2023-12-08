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
