#ifndef WALL_H
#define WALL_H

#include "Body.h"

class Wall : public Body {
private:
    double fLength;

public:
    Wall(Position pPosition, double pTraction, double pLength, int pInitiative)
    : Body(pPosition, 100, pTraction, pInitiative),
    fLength(pLength){

    }
 };

#endif //WALL_H
