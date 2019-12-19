#include <SFML/Graphics.hpp>
#include "Module.hh"
#include "Pompe.hh"
#include <iostream>
#include <string>

void initFont(sf::Font &font) {
	if (!font.loadFromFile("arial_narrow_7.ttf"))
	{
			exit(1);
	}
}

int main () {
	sf::Font font;
	initFont(font);
	Pompe p1("P1", &font);
	
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
			sf::Event event;
			while (window.pollEvent(event))
			{
					if (event.type == sf::Event::Closed)
							window.close();
			}

			window.clear();
			window.draw(p1.getName());
			window.display();
	}
	
	return 0;
}
