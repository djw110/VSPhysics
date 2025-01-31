//
// Created by danie on 1/22/2025.
//
#include "Instance.h"

#include <vector>
#include "Body.h"
#include "Wall.h"
#include "Utils.h"

using std::vector;

void Instance::collide(Body& pBody1, Body& pBody2) {
    vector<Velocity> newVelocities = utils::calcCollide(pBody1, pBody2);
    pBody1.updateVelocity(newVelocities[0]);
    pBody2.updateVelocity(newVelocities[1]);
}