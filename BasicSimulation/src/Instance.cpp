#include "Instance.h"
#include "Utils.h"

using std::vector;

//Set default gravScale to Earth's.
Instance::Instance(sf::RenderWindow& pWindow) : fWindow(pWindow){
    fGravScale = 9.807f;
}

//Get the sf:Shape from each body and draw it to the renderWindow. 
// "Pair" is a key,value pair in the dictionary of Body pointers
void Instance::drawBodies() {
    for (const auto& pair: fActiveBodies) {
        fWindow.draw(pair.second->getShape());
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

//Remove from activeBodies given ID
void Instance::removeBody(int pID) {
    fActiveBodies.erase(pID);
}