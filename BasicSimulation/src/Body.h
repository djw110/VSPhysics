#ifndef BODY_H
#define BODY_H

#include "Velocity.h"
#include "Position.h"
#include <SFML/Graphics.hpp>

class Body {
    protected:

    float fMass;
    float fTraction;
    Velocity fVelocity;
    Position fPosition;
    sf::Shape& fShape;
    int fInitiative;

    public:

    enum RotationDirection {CLOCK, COUNTERCLOCK};

    Body(Position pPosition, float pMass, float pTraction, int pInitiative, sf::Shape& pShape);

    virtual bool incrementPosition(float pIncX, float pIncY);

    virtual bool rotate(RotationDirection pRotation, float pMagnitude);

    virtual void remove();

    //Setters::
    void updateVelocity(Velocity& pNewVelocity) {
        fVelocity = pNewVelocity;
    }

    //Getters::
    Position getPosition() const {return fPosition;}
    float getMass() const {return fMass;}
    float getTraction() const {return fTraction;}
    Velocity getVelocity() const {return fVelocity;}

};


#endif //BODY_H
