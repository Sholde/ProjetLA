#include <SFML/Graphics.hpp>
#include <string>
#include "Class.hh"
#include "Constants.hh"
#include "Interface.hh"
#include "Pompe.hh"

Pompe::Pompe(float size, sf::Color color):shape(size), name() {
	this->shape.setFillColor(color);
	this->name.setPosition(this->shape.getPosition() + sf::Vector2<float>(size - 10, size - 20));
}

Pompe::~Pompe() {}

void Pompe::initName(const std::string &name, sf::Font &font, const int &size) {
	this->name.setString(name);
	this->name.setFont(font);
	this->name.setCharacterSize(size);
}

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
