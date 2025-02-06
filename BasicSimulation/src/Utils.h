#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include "Body.h"

//Collection of frequently used static math functions
namespace utils {

    const float cPI = 3.14159265359f;

    static float toRadians(float pAngle) {
        return pAngle * cPI / 180.0f;
    }

    static float toDegrees(float pAngle) {
        return pAngle * 180.0f / cPI;
    }

    //Calculate the movement of an object's X coordinate given an angle and magnitude
    static float calcIncrementX(float pBaseX, float pAngle, float pMagnitude) {
        return pBaseX + (cos(toRadians(pAngle)) * pMagnitude);
    }

    //Calculate the movement of an object's Y coordinate given an angle and magnitude
    static float calcIncrementY(float pBaseY, float pAngle, float pMagnitude) {
        return pBaseY + (sin(toRadians(pAngle)) * pMagnitude);
    }

    //Standardize an angle to be between 0-2pi
    static float standardAngle(float pAngle) {
        while (pAngle < 0) {
            pAngle += 2 * cPI;
        }
        while (pAngle >= 360){
            pAngle -= 2 * cPI;
        }
        return pAngle;
    }

    //Calculate angle of collision given the center points of 2 colliding objects. Between 0-2pi
    static float getCollisionAngle(float pCenter1X, float pCenter1Y, float pCenter2X, float pCenter2Y) {
        return atan2(pCenter2Y - pCenter1Y, pCenter2X - pCenter1X);
    }

    //Calculate the final velocity and acceleration of an object after colliding with another
    static Velocity calcCollide(const Body* pBody1, const std::shared_ptr<Body> pBody2) {

        //Attributes for calculation
        const float s1ix = pBody1->getPosition().getCenterX();
        const float s1iy = pBody1->getPosition().getCenterY();
        const float s2ix = pBody2->getPosition().getCenterX();
        const float s2iy = pBody2->getPosition().getCenterY();
        const float v1ix = pBody1->getVelocity().getSpeedX();
        const float v1iy = pBody1->getVelocity().getSpeedY();
        const float v2ix = pBody2->getVelocity().getSpeedX();
        const float v2iy = pBody2->getVelocity().getSpeedY();
        const float collisionAngle = getCollisionAngle(s1ix, s1iy, s2ix, s2iy);
        const float m1 = pBody1->getMass();
        const float m2 = pBody2->getMass();

        //Initial velocity of each object parallel to the collision and perpendicular to the collision
        const float v1iPar = v1ix*cos(collisionAngle) + v1iy*sin(collisionAngle);
        const float v2iPar = v2ix*cos(collisionAngle) + v2iy*sin(collisionAngle);
        const float v1Perp = -1*v1ix*sin(collisionAngle) + v1iy*cos(collisionAngle);
        const float v2Perp = -1*v2ix*sin(collisionAngle) + v2iy*cos(collisionAngle);

        //New velocity of body1 parallel to the collision
        const float v1fPar =( ( (m1 - m2) * v1iPar ) + (2 * m2 * v2iPar) ) / (m1 + m2);

        //Final values
        const float v1fx = ( v1fPar * cos(collisionAngle) ) - ( v1Perp * sin(collisionAngle) );
        const float v1fy = ( v1fPar * sin(collisionAngle) ) + ( v1Perp * cos(collisionAngle) );
        const float a1x = (v1fx - v1ix) / 0.000001f;
        const float a1y = (v1fy - v1iy) / 0.000001f;

        Velocity v1f = Velocity(v1fx,v1fy,a1x,a1y);

        return v1f;
    }

};

#endif //UTILS_H
