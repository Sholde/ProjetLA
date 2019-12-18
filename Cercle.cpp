#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"

Cercle::Cercle(float size, sf::Color color):shape(size) {
	this->shape.setFillColor(color);
	this->speed = 1;
}

Cercle::~Cercle() {}

void Cercle::initSystem(System* system) {
	this->system = system;
}

void Cercle::update() {
	this->time++;
	if(this->time == this->limit) {
		this->time = 0;
		if(this->shape.getPosition().x > 200) {
			this->speed = -1;
		}
		if(this->shape.getPosition().x < 0) {
			this->speed = 1;
		}
		this->shape.setPosition(this->shape.getPosition().x + this->speed, this->shape.getPosition().y);
	}
}

void Cercle::render() {
	this->system->window.draw(this->shape);
}
