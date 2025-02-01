#ifndef BALL_H
#define BALL_H

#include "Body.h"

class Ball : public Body {
private:
    sf::CircleShape fCircleShape;
    float fRadius;

public:
    Ball(Position pPosition, float pTraction, float pLength, int pInitiative) :
        fCircleShape(fRadius),
        Body(pPosition, 100, pTraction, pInitiative, fCircleShape),
        fRadius(pLength) {
    }
};

#endif //BALL_H
