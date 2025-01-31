#ifndef WALL_H
#define WALL_H

#include "Body.h"

class Wall : public Body {
private:
    double fLength;

public:
    Wall(Position pPosition, double pTraction, double pLength)
    : Body(pPosition, 100, pTraction),
    fLength(pLength){

    }
 };

#endif //WALL_H
