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

    public:

    enum RotationDirection {CLOCK, COUNTERCLOCK};

    Body(Position pPosition, double pMass, double pTraction);

    bool incrementPosition(double pIncX, double pIncY);

    bool rotate(RotationDirection pRotation, double pMagnitude);

    void remove();

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
