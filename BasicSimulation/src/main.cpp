#include "Instance.h"

/**
 * TODO: Hotkeys (a for add, r for remove, h for hit, p for pause
 */
int main() {
	auto window =  sf::RenderWindow(sf::VideoMode({1200,800}),"Game", sf::Style::Close | sf::Style::Titlebar);
	auto mainInstance = std::make_unique<Instance>(window);
	auto ball1 = std::make_shared<Ball>(Position(0,0,0),1,1,100,1);

	const auto onClose = [&window](const sf::Event::Closed&){
			window.close();
	};

	const auto onFocusGain = [&window](const sf::Event::FocusGained&) {
		//Unpause game unless manually paused
	};

	const auto onFocusLost = [&window](const sf::Event::FocusLost&) {
		//Pause game
	};

	const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed){
			switch (keyPressed.scancode) {
				case sf::Keyboard::Scancode::Escape:
					window.close();
					break;
			}
	};

	mainInstance->addBody(ball1);

	while (window.isOpen()) {
		window.handleEvents(onClose, onKeyPressed, onFocusGain, onFocusLost);
		window.clear();
		mainInstance->drawBodies();
		window.display();
	}

return 0;
}