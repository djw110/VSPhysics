#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include "Body.h"

using std::vector;

class Instance {
private:
    vector<std::shared_ptr<Body>> fCurrentBodies;
    float fGravitationScale;
    sf::RenderWindow& fWindow;

public:
    Instance(sf::RenderWindow& pWindow);

    bool addBody(std::shared_ptr<Body>);

    void removeBody(std::shared_ptr<Body>);
};

#endif //INSTANCE_H