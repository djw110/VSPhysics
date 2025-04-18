#ifndef BODY_H
#define BODY_H

#include "Velocity.h"
#include "Position.h"
#include <SFML/Graphics.hpp>

/*
An object rendered in the simulation, contained in an instance.
Affected by gravity and collisions with other objects.
Attributes associated with it's motion are stored in an associated Position and Velocity object.
*/
class Body {

protected:

    /*
    sf::Shape references the appearance of the body drawn onto the window
    ID is a unique ID to distinguish each body
    */
    float fMass;
    float fTraction;
    Velocity fVelocity;
    Position fPosition;
    std::shared_ptr<sf::Shape> fShape;
    int fID;

public:

    enum RotationDirection { CLOCK, COUNTERCLOCK };

    Body(Position pPosition, float pMass, float pTraction, std::shared_ptr<sf::Shape> pShape, int pID);

    virtual bool incrementPosition(float pIncX, float pIncY);

    virtual bool rotate(RotationDirection pRotation, float pMagnitude);

    virtual void collide(std::shared_ptr<Body> otherBody);

    //Setters:
    void updateVelocity(Velocity& pNewVelocity);

    //Getters:
    int getID() const { return fID; }
    float getMass() const {return fMass;}
    float getTraction() const {return fTraction;}
    Position getPosition() const { return fPosition; }
    Velocity getVelocity() const { return fVelocity; }
    std::shared_ptr<sf::Shape> getShape() { return fShape; }

    };


#endif //BODY_H
