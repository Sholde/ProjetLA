#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"

Cercle::Cercle(float size, sf::Color color):shape(size) {
	shape.setFillColor(color);
}

Cercle::~Cercle() {}

void Cercle::initSystem(System* system) {
	this->system = system;
}

void Cercle::update() {
	time++;
	if(time == limit) {
		time = 0;
		if(shape.getPosition().x > 200) {
			speed = -1;
		}
		if(shape.getPosition().x < 0) {
			speed = 1;
		}
		shape.setPosition(shape.getPosition().x + speed, shape.getPosition().y);
	}
}

void Cercle::render() {
	system->window.draw(shape);
}
