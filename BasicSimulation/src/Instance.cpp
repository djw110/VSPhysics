#include "Instance.h"

#include <vector>
#include "Body.h"
#include "Wall.h"
#include "Utils.h"

using std::vector;


//If pBody1 or pBody2 is not a wall, update their velocities post collision
void Instance::collide(Body& pBody1, Body& pBody2) {
    vector<Velocity> newVelocities = utils::calcCollide(pBody1, pBody2);
    if (!dynamic_cast<Wall*>(&pBody1)) {
        pBody1.updateVelocity(newVelocities[0]);
    }
    if (!dynamic_cast<Wall*>(&pBody1)) {
        pBody2.updateVelocity(newVelocities[1]);
    }
}