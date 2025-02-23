#ifdef TEST_MODE

#include <iostream>
#include "Instance.h"

bool testBody();
bool testInstance();
bool testUtils();

using std::cout;
using std::endl;

int main() {
    std::cout << "-- Testing Mode --" << std::endl;
    if (testBody()) {
        cout << "Passed all Body class tests" << endl;
    }
    if (testInstance()) {
        std::cout << "Passed all Instance class tests" << endl;
    }
    if (testUtils()) {
        cout << "Passed all Utils tests" << endl;
    }

    return 0;
}

bool testBody() {
    bool passed = true;
    
    auto testPos = std::make_shared<Position>(100,200,0.5);
    if (testPos->getCenterX() != 100 || testPos->getCenterY() != 200 || testPos->getOrientation() != 0.5) {
        passed = false;
        cout << "Failed Position constructor & getters" << endl;
    }

    auto testVel = std::make_shared <Velocity>(25, 50, 1.5,1.25);
    if (testVel->getSpeedX() != 25 || testVel->getSpeedY() != 50 || testVel->getAccelerationX() != 1.5 || testVel->getAccelerationY() != 1.25) {
        passed = false;
        cout << "Failed Velocity constructor & getters" << endl;
    }

    auto testBall = std::make_unique <Ball>(*testPos, 100, 0.65, 25.25, 12);
    if (testBall->getPosition().getCenterX() != 100 || testBall->getMass() != 100 || std::abs(testBall->getTraction() - 0.65) > 1e-6 || std::abs(testBall->getRadius() - 25.25) > 1e-6|| testBall->getID() != 12 || testBall->getVelocity().getAccelerationY() != 0){
        passed = false;
        cout << testBall->getPosition().getCenterX() << " " << testBall->getMass() << " " << testBall->getTraction() << " " << testBall->getRadius() << " " << testBall->getID() << " " << testBall->getVelocity().getAccelerationY() << endl;
        //cout << "Failed Ball constructor & getters" << endl;
    }

    auto testWall = std::make_unique <Wall>(*testPos, 0.5, 20, 13);
    if (testWall->getPosition().getCenterX() != 100 || testWall->getMass() != 1 || testWall->getTraction() != 0.5 || testWall->getLength() != 20 || testWall->getID() != 13 || testWall->getVelocity().getAccelerationY() != 0) {
        passed = false;
        cout << "Failed Wall constructor & getters" << endl;
    }

    std::unique_ptr<Body> testBall2 = std::make_unique<Ball>(*testPos, 100, 0.5, 25, 12);
    if (testBall2->getPosition().getCenterX() != 100 || testBall2->getMass() != 100 || testBall2->getTraction() != 0.5 || testBall2->getID() != 12 || testBall2->getVelocity().getAccelerationY() != 0) {
        passed = false;
        cout << "Failed Body inheritance" << endl;;
    }

    return passed;
}

bool testInstance() {
    bool passed = true;

    auto testPos = std::make_shared<Position>(100, 200, 0);
    auto testPos2 = std::make_shared<Position>(400, 500, 0.5); 
    
    auto window = sf::RenderWindow(sf::VideoMode({ 900,1100 }), "Testing", sf::Style::Close | sf::Style::Titlebar);
    auto testInstance = std::make_unique<Instance>(window);

    testInstance->addBall(*testPos, 10, 0.5, 25);
    if (testInstance->getBodyList().size() != 1 || testInstance->getBodyList()[0]->getMass() != 10) {
        passed = false;
        cout << "Failed addBall" << endl;
    }

    testInstance->addWall(*testPos2, 0.5, 20);
    if (testInstance->getBodyList().size() != 2 || testInstance->getBodyList()[1]->getTraction() != 0.5) {
        passed = false;
        cout << "Failed addWall" << endl;
    }

    testInstance->removeBody(100, 200);
    if (testInstance->getBodyList().size() != 1) {
        passed = false;
        cout << "Failed removeBody" << endl;
    }
    


    return passed;
}

bool testUtils() {
    bool passed = true;

    return passed;
}

#endif