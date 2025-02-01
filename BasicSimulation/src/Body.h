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

    virtual void collide(std::shared_ptr<Body> otherBody);

    //Setters::
    void updateVelocity(Velocity& pNewVelocity);

    //Getters::
    Position getPosition() const {return fPosition;}
    float getMass() const {return fMass;}
    float getTraction() const {return fTraction;}
    Velocity getVelocity() const {return fVelocity;}
    sf::Shape& getShape() { return fShape; }

};


#endif //BODY_H
