#include <SFML/Graphics.hpp>
#include <string>
#include "Class.hh"
#include "Constants.hh"
#include "Interface.hh"
#include "Pompe.hh"

Pompe::Pompe(sf::Text name, float size, sf::Color color):shape(size), name(name) {
	this->shape.setFillColor(color);
}

Pompe::~Pompe() {}

void Pompe::initInterface(Interface* interface) {
	this->interface = interface;
}

void Pompe::update() {
	this->time++;
	if(this->time == this->limit) {
		this->time = 0;
	}
}

void Pompe::render() {
	this->interface->window.draw(this->shape);
	this->interface->window.draw(this->name);
}
