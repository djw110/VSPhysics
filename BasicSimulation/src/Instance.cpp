#include "Instance.h"
#include "Utils.h"
#include <iostream>

using std::vector;

//Set default gravScale to Earth's.
Instance::Instance(sf::RenderWindow& pWindow) : fWindow(pWindow){
    fGravScale = 9.807f;
}

//Get the sf:Shape from each body and draw it to the renderWindow. 
// "Pair" is a key,value pair in the dictionary of Body pointers
void Instance::drawBodies() {
    for (const auto& pair: fActiveBodies) {
        fWindow.draw(*pair.second->getShape());
    }
}

//Insert to activeBodies with ID as key
bool Instance::addBall(Position pPosition, float pMass, float pTraction, float pRadius) {
    auto newBall = std::make_shared<Ball>(pPosition, pMass, pTraction, pRadius, fNextID);
    fActiveBodies.insert({ fNextID, newBall });
    fNextID++;
    return true;
}

//Insert to activeBodies with ID as key. Increments nextID.
bool Instance::addWall(Position pPosition, float pTraction, float pLength) {
    auto newWall = std::make_shared<Wall>(pPosition, pTraction, pLength, fNextID);
    fActiveBodies.insert({ fNextID, newWall });
    fNextID++;
    return true;
}


//Check if the parameters xBound and yBound fall within the areas covered by any bodies in the instance. 
// If so, remove them.
void Instance::removeBody(int pXBound, int pYBound) {
    for (auto it = fActiveBodies.begin(); it != fActiveBodies.end(); ) {
        Position bodyPos = it->second->getPosition();
        float bodyX = bodyPos.getCenterX();
        float bodyY = bodyPos.getCenterY();
        int ID = it->second->getID();

        if (Ball* ballPtr = dynamic_cast<Ball*>(it->second.get())) {
            float radius = ballPtr->getRadius();
            if (pXBound >= bodyX - radius &&
                pXBound <= bodyX + radius &&
                pYBound >= bodyY - radius &&
                pYBound <= bodyY + radius) {
                it = fActiveBodies.erase(it);
            }
            else {
                ++it;
            }
        }
        else {
            ++it;
        }
    }
}