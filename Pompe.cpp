#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, sf::Vector2f(st.x - 15, st.y + 40), db),
		pos_circle(st.x - 27.5, st.y + 30) {
	this->radius = 28.f;
	this->isActive = false;
	this->isFailure = false;
	this->isMain = false;
}

bool Pompe::getActive() {
	return this->isActive;
}

bool Pompe::getIsMain() {
	return this->isMain;
}

void Pompe::setActive() {
	this->isActive = !this->isActive;
}

void Pompe::setIsMain() {
	this->isMain = true;
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
	
	
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	if(!this->isMain) {
		draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
	}
}

