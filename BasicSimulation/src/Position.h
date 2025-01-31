#ifndef POSITION_H
#define POSITION_H

struct Position {
    double sfCenterX;
    double sfCenterY;
    double sfOrientation;

    Position(double pCenterX, double pCenterY, double pOrientation) :
    sfCenterX(pCenterX),
    sfCenterY(pCenterY),
    sfOrientation(pOrientation) {}

    double getCenterX() const { return sfCenterX; }
    double getCenterY() const { return sfCenterY; }
    double getOrientation() const { return sfOrientation; }
};

#endif //POSITION_H
