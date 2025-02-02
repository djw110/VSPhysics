#include "Instance.h"
#include "Utils.h"

using std::vector;

Instance::Instance(sf::RenderWindow& pWindow) : fWindow(pWindow){
    fGravitationScale = 9.807f;
}

void Instance::drawBodies() {
    for (std::shared_ptr<Body> lBody: fCurrentBodies) {
        fWindow.draw(lBody->getShape());
    }
}

bool Instance::addBody(std::shared_ptr<Body> pBody) {
    fCurrentBodies.push_back(pBody);
    return true;
}