#include "Body.h"
#include <SFML/Graphics.hpp>

/**
 * TODO: Hotkeys (a for add, r for remove, h for hit
 */
int main() {
	auto window =  sf::RenderWindow(sf::VideoMode({1200,800}),"Game", sf::Style::Close | sf::Style::Titlebar);
	sf::CircleShape body1(100.f);

	const auto onClose = [&window](const sf::Event::Closed&){
			window.close();
	};

	const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed){
			switch (keyPressed.scancode) {
				case sf::Keyboard::Scancode::Escape:
					window.close();
					break;
				}
	};

	while (window.isOpen()) {
		window.handleEvents(onClose, onKeyPressed);
		window.clear();
		window.draw(body1);
		window.display();
    }

return 0;
}