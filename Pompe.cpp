#include <SFML/Graphics.hpp>
#include "Include.hh"

Pompe::Pompe(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, sf::Vector2f(st.x - 15, st.y + 40), db),
		box_circle(sf::Vector2f(st.x - 27.5, st.y + 30), 28, 5) {
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
	this->box_circle.setColor(this->color);
}

void Pompe::render(Interface *interface) {
	this->box_circle.render(interface);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	if(!this->isMain) {
		draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
	}
}

