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

void Body::remove() {
    fMass = 0;
    fVelocity = Velocity(0,0,0,0);
}