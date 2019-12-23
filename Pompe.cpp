#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(const char* name, sf::Vector2f pos)
		:Module(name, sf::Vector2f(pos.x - 15, pos.y + 40)),
		pos_circle(pos.x - 27.5, pos.y + 30) {
	this->radius = 28.f;
	this->isActive = false;
	this->isFailure = false;
}

bool Pompe::getActive() {
	return this->isActive;
}

void Pompe::setActive(bool boolean) {
	this->isActive = boolean;
}

void Pompe::update() {
	if(this->isActive) {
		this->color = sf::Color::Green;
	}
	else {
		this->color = sf::Color::Red;
	}
}

void Pompe::render(Interface *interface) {
	int DECAL = 3;
	draw_circle(interface->statement, this->pos_circle, this->radius, sf::Color::Black);
	sf::Vector2f tmp = sf::Vector2f(this->pos_circle.x + DECAL, this->pos_circle.y + DECAL);
	draw_circle(interface->statement, tmp, this->radius - DECAL, this->color);
	
	
	draw_text(interface->statement, this->pos_text, this->name, interface->font, 25, sf::Color::Black);
}

