#include "unit.hpp"
#include "objectCreator.hpp"
#include<vector>
#include<list>
#include<typeinfo>
#include<iterator>
#include "Lazer.hpp"

using namespace std;

class LazerMaker{
    //Create your list here
    vector<Unit*> lazerVector;
    public:
    void drawObjects(); 
    void createObject(int, int);
    void removeObject(Unit*);
    vector<Unit*> returnLazerVector();
    ~LazerMaker();
};

