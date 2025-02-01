#include <vector>
#include "Body.h"
#include "Utils.h"

Body::Body(Position pPosition, float pMass, float pTraction, int pInitiative, sf::Shape& pShape) :
    fPosition(pPosition),
    fMass(pMass),
    fTraction(pTraction),
    fInitiative(pInitiative),
    fVelocity(Velocity(0,0,0,0)),
    fShape(pShape){
}

bool Body::incrementPosition(float pIncX, float pIncY) {
    fPosition.sfCenterX += pIncX;
    fPosition.sfCenterY += pIncY;
    return true;
}

void Body::updateVelocity(Velocity& pNewVelocity) {
    fVelocity = pNewVelocity;
}

bool Body::rotate(RotationDirection pRotation, float pMagnitude) {
    float result = fPosition.sfOrientation;
    switch (pRotation) {
        case CLOCK:
            result += pMagnitude;
        case COUNTERCLOCK:
            result -= pMagnitude;
    }
    fPosition.sfOrientation = utils::standardAngle(result);
    return true;
}

void Body::collide(std::shared_ptr<Body> otherBody) {
    Velocity v = utils::calcCollide(this, otherBody);
    updateVelocity(v);
}