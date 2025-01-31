#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <vector>
#include "Position.h"
#include "Velocity.h"

namespace utils {

    static double toRadians(double pAngle) {
        return pAngle * 3.14 / 180.0;
    }

    static double toDegrees(double pAngle) {
        return pAngle * 180.0 / 3.14;
    }

    static double calcIncrementX(double pBaseX, double pAngle, double pMagnitude) {
        return pBaseX + (cos(toRadians(pAngle)) * pMagnitude);
    }

    static double calcIncrementY(double pBaseY, double pAngle, double pMagnitude) {
        return pBaseY + (sin(toRadians(pAngle)) * pMagnitude);
    }

    static double standardAngle(double pAngle) {
        pAngle = (toDegrees(pAngle));
        while (pAngle < 0) {
            pAngle += 360;
        }
        while (pAngle >= 360){
            pAngle -= 360;
        }
        return toRadians(pAngle);
    }

    static double getCollisionAngle(double pCenter1X, double pCenter1Y, double pCenter2X, double pCenter2Y) {
        return atan2(pCenter2Y - pCenter1Y, pCenter2X - pCenter1X);
    }

    static std::vector<Velocity> calcCollide(Body& pBody1, Body& pBody2) {
        const double s1ix = pBody1.getPosition().getCenterX();
        const double s1iy = pBody1.getPosition().getCenterY();
        const double s2ix = pBody2.getPosition().getCenterX();
        const double s2iy = pBody2.getPosition().getCenterY();
        const double v1ix = pBody1.getVelocity().getSpeedX();
        const double v1iy = pBody1.getVelocity().getSpeedY();
        const double v2ix = pBody2.getVelocity().getSpeedX();
        const double v2iy = pBody2.getVelocity().getSpeedY();
        const double collisionAngle = getCollisionAngle(s1ix, s1iy, s2ix, s2iy);
        const double m1 = pBody1.getMass();
        const double m2 = pBody2.getMass();

        const double v1iPar = v1ix*cos(collisionAngle) + v1iy*sin(collisionAngle);
        const double v2iPar = v2ix*cos(collisionAngle) + v2iy*sin(collisionAngle);
        const double v1Perp = -1*v1ix*sin(collisionAngle) + v1iy*cos(collisionAngle);
        const double v2Perp = -1*v2ix*sin(collisionAngle) + v2iy*cos(collisionAngle);

        const double v1fPar =( ( (m1 - m2) * v1iPar ) + (2 * m2 * v2iPar) ) / (m1 + m2);
        const double v2fPar =( ( (m2 - m1) * v2iPar ) + (2 * m1 * v1iPar) ) / (m1 + m2);

        const double v1fx = ( v1fPar * cos(collisionAngle) ) - ( v1Perp * sin(collisionAngle) );
        const double v1fy = ( v1fPar * sin(collisionAngle) ) + ( v1Perp * cos(collisionAngle) );
        const double v2fx = ( v2fPar * cos(collisionAngle) ) - ( v2Perp * sin(collisionAngle) );
        const double v2fy = ( v2fPar * sin(collisionAngle) ) + ( v2Perp * cos(collisionAngle) );

        const double a1x = (v1fx - v1ix) / 0.000001;
        const double a1y = (v1fy - v1iy) / 0.000001;
        const double a2x = (v2fx - v2ix) / 0.000001;
        const double a2y = (v2fy - v2iy) / 0.000001;

        Velocity v1f = Velocity(v1fx,v1fy,a1x,a1y);
        Velocity v2f = Velocity(v2fx,v2fy,a2x,a2y);

        return {v1f,v2f};
    }

};

#endif //UTILS_H
