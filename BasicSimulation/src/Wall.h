#ifndef WALL_H
#define WALL_H

#include "Body.h"

class Wall : public Body {
private:
    sf::RectangleShape fRectangleShape;
    float fLength;

public:
    Wall(Position pPosition, float pTraction, float pLength, int pInitiative): 
        fRectangleShape({fLength,1}),
        Body(pPosition, 100, pTraction, pInitiative, fRectangleShape),
        fLength(pLength){
    }
 };

#endif //WALL_H
