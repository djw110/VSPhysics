#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <vector>
#include "Body.h"

namespace utils {

    static float toRadians(float pAngle) {
        return pAngle * 3.14 / 180.0;
    }

    static float toDegrees(float pAngle) {
        return pAngle * 180.0 / 3.14;
    }

    static float calcIncrementX(float pBaseX, float pAngle, float pMagnitude) {
        return pBaseX + (cos(toRadians(pAngle)) * pMagnitude);
    }

    static float calcIncrementY(float pBaseY, float pAngle, float pMagnitude) {
        return pBaseY + (sin(toRadians(pAngle)) * pMagnitude);
    }

    static float standardAngle(float pAngle) {
        pAngle = (toDegrees(pAngle));
        while (pAngle < 0) {
            pAngle += 360;
        }
        while (pAngle >= 360){
            pAngle -= 360;
        }
        return toRadians(pAngle);
    }

    static float getCollisionAngle(float pCenter1X, float pCenter1Y, float pCenter2X, float pCenter2Y) {
        return atan2(pCenter2Y - pCenter1Y, pCenter2X - pCenter1X);
    }

    static std::vector<Velocity> calcCollide(Body& pBody1, Body& pBody2) {
        const float s1ix = pBody1.getPosition().getCenterX();
        const float s1iy = pBody1.getPosition().getCenterY();
        const float s2ix = pBody2.getPosition().getCenterX();
        const float s2iy = pBody2.getPosition().getCenterY();
        const float v1ix = pBody1.getVelocity().getSpeedX();
        const float v1iy = pBody1.getVelocity().getSpeedY();
        const float v2ix = pBody2.getVelocity().getSpeedX();
        const float v2iy = pBody2.getVelocity().getSpeedY();
        const float collisionAngle = getCollisionAngle(s1ix, s1iy, s2ix, s2iy);
        const float m1 = pBody1.getMass();
        const float m2 = pBody2.getMass();

        const float v1iPar = v1ix*cos(collisionAngle) + v1iy*sin(collisionAngle);
        const float v2iPar = v2ix*cos(collisionAngle) + v2iy*sin(collisionAngle);
        const float v1Perp = -1*v1ix*sin(collisionAngle) + v1iy*cos(collisionAngle);
        const float v2Perp = -1*v2ix*sin(collisionAngle) + v2iy*cos(collisionAngle);

        const float v1fPar =( ( (m1 - m2) * v1iPar ) + (2 * m2 * v2iPar) ) / (m1 + m2);
        const float v2fPar =( ( (m2 - m1) * v2iPar ) + (2 * m1 * v1iPar) ) / (m1 + m2);

        const float v1fx = ( v1fPar * cos(collisionAngle) ) - ( v1Perp * sin(collisionAngle) );
        const float v1fy = ( v1fPar * sin(collisionAngle) ) + ( v1Perp * cos(collisionAngle) );
        const float v2fx = ( v2fPar * cos(collisionAngle) ) - ( v2Perp * sin(collisionAngle) );
        const float v2fy = ( v2fPar * sin(collisionAngle) ) + ( v2Perp * cos(collisionAngle) );

        const float a1x = (v1fx - v1ix) / 0.000001;
        const float a1y = (v1fy - v1iy) / 0.000001;
        const float a2x = (v2fx - v2ix) / 0.000001;
        const float a2y = (v2fy - v2iy) / 0.000001;

        Velocity v1f = Velocity(v1fx,v1fy,a1x,a1y);
        Velocity v2f = Velocity(v2fx,v2fy,a2x,a2y);

        return {v1f,v2f};
    }

};

#endif //UTILS_H
