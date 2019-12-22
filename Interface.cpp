
#include <SFML/Graphics.hpp>
#include "Include.hh"

Interface::Interface(const char* name, int width, int height):window(sf::VideoMode(width, height), name), font() {
	this->width = width;
	this->height = height;
	if (!this->font.loadFromFile("arial_narrow_7.ttf")) {
		exit(1);
	}
}

Interface::~Interface() {}

void Interface::initSystem(System *s) {
	this->system = s;
}

void Interface::start() {
	while (window.isOpen())
    {
        sf::Event event;
        // update
        system->update();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // render
        system->render(this);
        window.display();
    }
}
