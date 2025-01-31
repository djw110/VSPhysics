#ifndef VELOCITY_H
#define VELOCITY_H

struct Velocity {
    double sfSpeedX;
    double sfSpeedY;
    double sfAccelerationX;
    double sfAccelerationY;

    Velocity(double pSpeedX, double pSpeedY, double pAccelerationX, double pAccelerationY) :
    sfSpeedX(pSpeedX),
    sfSpeedY(pSpeedY),
    sfAccelerationX(pAccelerationX),
    sfAccelerationY(pAccelerationY) {}

    double getSpeedX() const { return sfSpeedX; }
    double getSpeedY() const { return sfSpeedY; }
    double getAccelerationX() const { return sfAccelerationX; }
    double getAccelerationY() const { return sfAccelerationY; }
};

#endif //VELOCITY_H
