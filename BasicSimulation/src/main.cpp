#include "Instance.h"
#include <random>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;

/**
 * TODO: Hotkeys (a for add, r for remove, h for hit, p for pause
 */

int getInputInt(string pMessage, int pLowerBound, int pUpperBound);
float getInputFloat(string pMessage, int pLowerBound, int pUpperBound);

//Create an application window to render a game instance.
int main() {

	//Create application window, game instance, and a testing body
	auto window =  sf::RenderWindow(sf::VideoMode({900,1100}),"Game", sf::Style::Close | sf::Style::Titlebar);
	auto mainInstance = std::make_unique<Instance>(window);

	//Close application window and stop instance on user selection
	const auto onClose = [&window](const sf::Event::Closed&){
			window.close();
	};

	//Unpause game unless manually paused (on maximize) (*TBA*)
	const auto onFocusGain = [&window](const sf::Event::FocusGained&) {	};

	//Pause game on maximize, (*TBA*)
	const auto onFocusLost = [&window](const sf::Event::FocusLost&) {	};

	//Handle user hotkey input (1 key at a time)
	const auto onKeyPressed = [&window, &mainInstance](const sf::Event::KeyPressed& keyPressed){
			switch (keyPressed.scancode) {

				case sf::Keyboard::Scancode::Escape:
					window.close();
					break;

				case sf::Keyboard::Scancode::A:
				{
					float iRadius = getInputFloat("Radius: ", 10, 100);
					int bound = (int)(std::ceil(iRadius));
					float iXCoordinate = getInputFloat("Position (x) : ", 1 + bound, 899 - bound);
					float iYCoordinate = getInputFloat("Position (y): ", 1 + bound, 1099 - bound);
					float iMass = getInputFloat("Mass: ", 1, 1000);
					float iTraction = getInputFloat("Traction: ", 0, 1);
					mainInstance->addBall(Position(iXCoordinate, iYCoordinate, 0), iMass, iTraction, iRadius);
				}
					break;

				case sf::Keyboard::Scancode::R:
					sf::Vector2i mousePosVec = sf::Mouse::getPosition(window);
					mainInstance->removeBody(mousePosVec.x, mousePosVec.y);
					break;

			}
	};

	//While game running: handle all events, clear frame, then redraw and display new frame.
	while (window.isOpen()) {
		window.handleEvents(onClose, onKeyPressed, onFocusGain, onFocusLost);
		window.clear();
		mainInstance->drawBodies();
		window.display();
	}

return 0;
}

int getInputInt(string pMessage, int pLowerBound, int pUpperBound){
	string iCandidate;
	int iInt;
	std::stringstream ss;
	cout << pMessage;
	bool validInput = false;

	while (!validInput) {
		ss.clear();
		ss.str("");
		getline(cin, iCandidate);
		ss << iCandidate;

		if (iCandidate.empty()) {
			cout << "No input. Input a integer: ";
		}
		else {
			ss >> iInt;
			if (ss.fail()) {
				cout << "Invalid input. Enter an integer: ";
			}
			else {
				std::streampos pos = ss.tellg();
				if (pos < ss.str().size()) {
					cout << "Invalid input. Enter an integer: ";
				}
				else if(iInt < pLowerBound || iInt > pUpperBound) {
					cout << "Not in bounds. Please enter an integer between " << pLowerBound << " and " << pUpperBound << ": ";
				}
				else {
					validInput = true;
				}
			}
		}
	}
	return iInt;
}

float getInputFloat(string pMessage, int pLowerBound, int pUpperBound) {
	string iCandidate;
	float iFloat;
	std::stringstream ss;
	cout << pMessage;
	bool validInput = false;

	while (!validInput) {
		ss.clear();
		ss.str("");
		getline(cin, iCandidate);
		ss << iCandidate;

		if (iCandidate.empty()) {
			cout << "No input. Input a float: ";
		}
		else {
			ss >> iFloat;
			if (ss.fail()) {
				cout << "Invalid input. Enter a float: ";
			}
			else {
				std::streampos pos = ss.tellg();
				if (pos < ss.str().size()) {
					cout << "Invalid input. Enter a float: ";
				}
				else if (iFloat < pLowerBound || iFloat > pUpperBound) {
					cout << "Not in bounds. Please enter an integer between " << pLowerBound << " and " << pUpperBound << ": ";
				}
				else {
					validInput = true;
				}
			}
		}
	}
	return iFloat;
}