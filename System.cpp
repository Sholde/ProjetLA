#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"

System::System():window(sf::VideoMode(400, 200), "Test"), composant() {}

System::~System() {}

void System::add(Cercle* c) {
	this->composant.push_back(c);
}

void System::handleEvent(sf::Event event) {
	while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();
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
