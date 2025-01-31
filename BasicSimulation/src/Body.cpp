#include <vector>
#include "Body.h"
#include "Utils.h"

Body::Body(Position pPosition, double pMass, double pTraction) :
    fPosition(pPosition),
    fMass(pMass),
    fTraction(pTraction),
    fVelocity(Velocity(0,0,0,0)){
}

bool Body::incrementPosition(double pIncX, double pIncY) {
    fPosition.sfCenterX += pIncX;
    fPosition.sfCenterY += pIncY;
    return true;
}

bool Body::rotate(RotationDirection pRotation, double pMagnitude) {
    double result = fPosition.sfOrientation;
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