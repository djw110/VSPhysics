#include "Body.h"
#include "Utils.h"


//Initialize all fields. Set position of the SFML "Shape" in the render window to the correct position.
Body::Body(Position pPosition, float pMass, float pTraction, std::shared_ptr<sf::Shape>pShape, int pID) :
    fPosition(pPosition),
    fMass(pMass),
    fTraction(pTraction),
    fVelocity(Velocity(0, 0, 0, 0)),
    fShape(pShape),
    fID(pID) {  }

//Increment center position based on current position
bool Body::incrementPosition(float pIncX, float pIncY) {
    fPosition.sfCenterX += pIncX;
    fPosition.sfCenterY += pIncY;
    return true;
}

void Body::updateVelocity(Velocity& pNewVelocity) {
    fVelocity = pNewVelocity;
}

//Calculate final rotation based on current rotation, then standardize result between 0-2pi
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

//Calculate new velocity for *this given a collision with another body, then update
void Body::collide(std::shared_ptr<Body> otherBody) {
    Velocity v = utils::calcCollide(this, otherBody);
    updateVelocity(v);
}