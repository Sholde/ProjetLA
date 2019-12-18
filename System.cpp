#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"

System::System():window(sf::VideoMode(400, 200), "Test"), composant() {
	Cercle c1(this);
	this->composant.push_back(c1);
}

System::~System() {}

void System::update() {
	for(Cercle c : composant) {
		c.update();
	}
}

void System::render() {
	window.clear();
	for(Cercle c : composant) {
		c.render();
	}
	window.display();
}
