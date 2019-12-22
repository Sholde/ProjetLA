#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(const char* name, int x, int y)
		:Module(name, x - 15, y + 40),
		pos_circle(x - 27.5, y + 30) {
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
	draw_circle(interface, this->pos_circle, this->radius, sf::Color(0, 100, 0));
	sf::Vector2f tmp = sf::Vector2f(this->pos_circle.x + DECAL, this->pos_circle.y + DECAL);
	draw_circle(interface, tmp, this->radius - DECAL, this->color);
	
	
	draw_text(interface, this->pos_text, this->name, interface->font, 25, sf::Color::White);
}

