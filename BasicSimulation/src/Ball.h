#ifndef BALL_H
#define BALL_H

#include "Body.h"

class Ball : public Body {
private:
    sf::CircleShape fCircleShape;
    float fRadius;

public:
    Ball(Position pPosition, float pMass, float pTraction, float pRadius, int pInitiative) :
        fRadius(pRadius),
        fCircleShape(pRadius),
        Body(pPosition, pMass, pTraction, pInitiative, fCircleShape)
        {
    }
};

#endif //BALL_H
