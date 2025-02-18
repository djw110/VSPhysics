#ifndef BALL_H
#define BALL_H

#include "Body.h"

//Type of Body, a Circle, has a radius.
class Ball : public Body {
private:
    float fRadius;

public:

    /*Create a regular body with a sf::CircleShape using the radius*/
    Ball(Position pPosition, float pMass, float pTraction, float pRadius, int pID) :
        Body(pPosition, pMass, pTraction, std::make_shared<sf::CircleShape>(pRadius), pID),
        fRadius(pRadius)
        {
        fShape->setOrigin({ pRadius,pRadius });
        fShape->setPosition({ fPosition.sfCenterX,fPosition.sfCenterY });
    }

    float getRadius() { return fRadius; }

};

#endif //BALL_H
