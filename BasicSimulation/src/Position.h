#ifndef POSITION_H
#define POSITION_H

struct Position {
    float sfCenterX;
    float sfCenterY;
    float sfOrientation;

    Position(float pCenterX, float pCenterY, float pOrientation) :
    sfCenterX(pCenterX),
    sfCenterY(pCenterY),
    sfOrientation(pOrientation) {}

    float getCenterX() const { return sfCenterX; }
    float getCenterY() const { return sfCenterY; }
    float getOrientation() const { return sfOrientation; }
};

#endif //POSITION_H
