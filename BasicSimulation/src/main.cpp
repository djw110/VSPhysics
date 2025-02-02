#include "Instance.h"

/**
 * TODO: Hotkeys (a for add, r for remove, h for hit, p for pause
 */

//Create an application window to render a game instance.
int main() {

	//Create application window, game instance, and a testing body
	auto window =  sf::RenderWindow(sf::VideoMode({1200,800}),"Game", sf::Style::Close | sf::Style::Titlebar);
	auto mainInstance = std::make_unique<Instance>(window);
	mainInstance->addBall(Position(0, 0, 0), 1, 1, 100);

	//Close application window and stop instance on user selection
	const auto onClose = [&window](const sf::Event::Closed&){
			window.close();
	};

	//Unpause game unless manually paused (on maximize)
	const auto onFocusGain = [&window](const sf::Event::FocusGained&) {	};

	//Pause game on maximize
	const auto onFocusLost = [&window](const sf::Event::FocusLost&) {	};

	//Handle user hotkey input (1 key at a time)
	const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed){
			switch (keyPressed.scancode) {

				//Close and stop instance on input "Esc"
				case sf::Keyboard::Scancode::Escape:
					window.close();
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