#ifndef INSTANCE_H
#define INSTANCE_H

#include <unordered_map>
#include "Ball.h"
#include "Wall.h"

using std::vector;

//Manages the collection of bodies as a whole
class Instance {
private:
    
    std::unordered_map<int, std::shared_ptr<Body>> fActiveBodies;
    float fGravScale;
    int fNextID = 0;
    sf::RenderWindow& fWindow;

public:
    Instance(sf::RenderWindow& pWindow);

    //Draws all active bodies to the window
    void drawBodies();

    //Add body to activeBodies
    bool addBall(Position pPosition, float pMass, float pTraction, float pRadius);
    bool addWall(Position pPosition, float pTraction, float pLength);

    //Removes body from activeBodies
    void removeBody(int pXBound, int pYBound);

    std::unordered_map<int, std::shared_ptr<Body>> getBodyList() { return fActiveBodies; }
    float getGravScale() { return fGravScale; }
    int getNextID() { return fNextID; }
};

#endif //INSTANCE_H