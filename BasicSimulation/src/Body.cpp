#include "Body.h"
#include "Utils.h"

Body::Body(Position pPosition, float pMass, float pTraction, sf::Shape& pShape, int pID) :
    fPosition(pPosition),
    fMass(pMass),
    fTraction(pTraction),
    fVelocity(Velocity(0,0,0,0)),
    fShape(pShape),
    fID(pID) { }

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
            break;
        case COUNTERCLOCK:
            result -= pMagnitude;
            break;
    }
    fPosition.sfOrientation = utils::standardAngle(result);
    return true;
}

void Body::collide(std::shared_ptr<Body> otherBody) {
    Velocity v = utils::calcCollide(this, otherBody);
    updateVelocity(v);
}