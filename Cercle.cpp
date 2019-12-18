#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"

Cercle::Cercle(System* system):shape(100.f) {
	this->system = system;
	shape.setFillColor(sf::Color::Green);
}

Cercle::~Cercle() {}

void Cercle::update() {
	if(shape.getPosition().x > 200) {
    speed = -1;
  }
  else if(shape.getPosition().x < 0) {
    speed = 1;
  }
  shape.setPosition(shape.getPosition().x + speed, shape.getPosition().y);
}

void Cercle::render() {
	system->window.draw(this->shape);
}
