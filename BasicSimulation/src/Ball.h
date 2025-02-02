#ifndef BALL_H
#define BALL_H

#include "Body.h"

//Type of Body, a Circle, has a radius.
class Ball : public Body {
private:
    sf::CircleShape fCircleShape;
    float fRadius;

public:

    /*Create a regular body with a sf::CircleShape using the radius*/
    Ball(Position pPosition, float pMass, float pTraction, float pRadius, int pID) :
        fRadius(pRadius),
        fCircleShape(pRadius),
        Body(pPosition, pMass, pTraction, fCircleShape, pID)
        {  }

};

#endif //BALL_H
