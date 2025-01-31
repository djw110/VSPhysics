#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include "Body.h"

using std::vector;

class Instance {
private:
    vector<Body> fCurrentBodies;
    int fGravitationScale;

    public:
    Instance();

    bool addBody(Body& pBody);

    void removeBody(Body& pBody);

    static void collide(Body& pBody1, Body& pBody2);
};

#endif //INSTANCE_H