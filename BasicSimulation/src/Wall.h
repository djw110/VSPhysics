#ifndef WALL_H
#define WALL_H

#include "Body.h"

//Type of Body, a Rectangle, only has a length. Cannot be affected by gravity or collisions.
class Wall : public Body {
private:
    float fLength;

public:

    /*Create a regular body with a sf::RectangleShape with a width of 1.
    Arbitary mass given b/c wall cannot move.*/
    Wall(Position pPosition, float pTraction, float pLength, int pID):
        Body(pPosition, 1, pTraction, std::make_shared<sf::RectangleShape>(sf::Vector2f(pLength, 1)), pID),
        fLength(pLength){  }

 };

#endif //WALL_H
