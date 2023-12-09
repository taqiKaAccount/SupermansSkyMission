#include "unit.hpp"
#include "objectCreator.hpp"
#include<vector>
#include<list>
#include<typeinfo>
#include<iterator>
#include "bullet.hpp"

using namespace std;

class BulletMaker{
    //Create your list here
    vector<Unit*> BulletVector;
    public:
    void drawObjects(); 
    void createObject(int, int);
    void removeObject(Unit*);
    vector<Unit*> returnBulletVector();
};
