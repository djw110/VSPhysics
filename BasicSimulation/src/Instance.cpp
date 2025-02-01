#include "Instance.h"
#include "Wall.h"
#include "Utils.h"
#include "Ball.h"

using std::vector;

Instance::Instance(sf::RenderWindow& pWindow) : fWindow(pWindow){
    fGravitationScale = 9.807f;
}

bool Instance::addBody(std::shared_ptr<Body> pBody) {
    fCurrentBodies.push_back(pBody);
    fWindow.draw(pBody->getShape());
}