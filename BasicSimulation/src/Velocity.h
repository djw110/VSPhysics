#ifndef VELOCITY_H
#define VELOCITY_H

//Contains information about a Body's behavior over the x,y axes
struct Velocity {
    float sfSpeedX;
    float sfSpeedY;
    float sfAccelerationX;
    float sfAccelerationY;

    Velocity(float pSpeedX, float pSpeedY, float pAccelerationX, float pAccelerationY) :
    sfSpeedX(pSpeedX),
    sfSpeedY(pSpeedY),
    sfAccelerationX(pAccelerationX),
    sfAccelerationY(pAccelerationY) {}

    float getSpeedX() const { return sfSpeedX; }
    float getSpeedY() const { return sfSpeedY; }
    float getAccelerationX() const { return sfAccelerationX; }
    float getAccelerationY() const { return sfAccelerationY; }
};

#endif //VELOCITY_H
