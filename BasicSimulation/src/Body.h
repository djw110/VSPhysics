#ifndef BODY_H
#define BODY_H

#include "Velocity.h"
#include "Position.h"

class Body {
    private:

    double fMass;
    double fTraction;
    Velocity fVelocity;
    Position fPosition;
    int fInitiative;

    public:

    enum RotationDirection {CLOCK, COUNTERCLOCK};

    Body(Position pPosition, double pMass, double pTraction, int pInitiative);

    virtual bool incrementPosition(double pIncX, double pIncY);

    virtual bool rotate(RotationDirection pRotation, double pMagnitude);

    virtual void remove();

    //Setters::
    void updateVelocity(Velocity& pNewVelocity) {
        fVelocity = pNewVelocity;
    }

    //Getters::
    Position getPosition() const {return fPosition;}
    double getMass() const {return fMass;}
    double getTraction() const {return fTraction;}
    Velocity getVelocity() const {return fVelocity;}

};


#endif //BODY_H
