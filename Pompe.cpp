#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(const char* name, const sf::Vector2f &st)
		:Module(name, st),
		circle(sf::Vector2f(st.x - st_pompe_x, st.y - st_pompe_y), st_pompe_radius, MARGIN),
		button(sf::Vector2f(0, 0), box_size_x, box_size_y, box_margin) {
	this->isActive = false;
	this->isFailure = false;
	this->isMain = true;
}

Pompe::Pompe(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, st),
		circle(sf::Vector2f(st.x - st_pompe_x, st.y - st_pompe_y), st_pompe_radius, MARGIN),
		button(sf::Vector2f(db.x - 30, db.y), box_size_x, box_size_y, box_margin),
		pos_db(db) {
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

bool Pompe::checkFeed() {
	if(this->isFailure || !this->isActive)
		return false;
	else
		return true;
}

void Pompe::handleClic(int &x, int &y) {
	if(!this->isMain) {
		if(this->button.isClicOn(x, y)) {
			this->isActive = !this->isActive;
		}
	}
}

void Pompe::update() {
	if(this->isFailure && this->isActive) {
		this->isActive = false;
	}
}

void Pompe::render(Interface *interface) {
	if(this->isActive) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
	
	this->circle.render(interface);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	if(!this->isMain) {
		this->button.render(interface->dashboard);
		draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
	}
}

