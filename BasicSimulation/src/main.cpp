#include "Body.h"
#include <SFML/Graphics.hpp>

/**
 * TODO: Hotkeys (a for add, r for remove, h for hit
 */
int main() {
	auto window =  sf::RenderWindow(sf::VideoMode({512,512}),"Game");
	sf::CircleShape body1(100.f);

    while (window.isOpen()) {
	    while(const std::optional windowEvent = window.pollEvent()) {
		    {
		    	if (windowEvent -> is <sf::Event::Closed>()) {
		    		window.close();
		    	}
		    }
	    	window.clear();
	    	window.draw(body1);
	    	window.display();
	    }

    }

return 0;
}