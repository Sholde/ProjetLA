#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "Interface.hh"
#include "Pompe.hh"

Interface::Interface(int width, int heigth, const char* name):
	window(sf::VideoMode(width, heigth), name),
	composant(),
	font() {
	
	if (!font.loadFromFile("arial_narrow_7.ttf"))
	{
			exit(1);
	}
}

Interface::~Interface() {}

void Interface::add(Pompe* c) {
	c->initInterface(this);
	this->composant.push_back(c);
}

void Interface::handleEvent(sf::Event event) {
	if(window.hasFocus()) {
		while (window.pollEvent(event))
	  {
	    if (event.type == sf::Event::Closed)
	      window.close();
	  }
	}
}

void Interface::update() {
	for(Pompe* p : composant) {
		p->update();
	}
}

void Interface::render() {
	window.clear();
	for(Pompe* p : composant) {
		p->render();
	}
	window.display();
}

void Interface::close() {
	if(window.isOpen()) {
		window.close();
	}
}
