#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"
#include <iostream>

System::System(int width, int heigth):window(sf::VideoMode(width, heigth), "System"), composant() {}

System::~System() {}

void System::add(Cercle* c) {
	c->initSystem(this);
	this->composant.push_back(c);
}

void System::handleEvent(sf::Event event) {
	while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();
      std::cout << "ferme event" << std::endl;
  }
}

void System::update() {
	for(Cercle* c : composant) {
		c->update();
	}
}

void System::render() {
	window.clear();
	for(Cercle* c : composant) {
		c->render();
	}
	window.display();
}

void System::close() {
	if(window.isOpen()) {
		window.close();
		std::cout << "ferme close" << std::endl;
	}
}
