#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, sf::Vector2f(st.x - 15, st.y + 40)),
		circle(sf::Vector2f(st.x - 27.5, st.y + 30), 28, 5),
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

void Pompe::handleClic(int &x, int &y) {
	sf::Vector2f pos = this->button.getPoint();
	sf::Vector2f size = this->button.getSize();
	
	if(x >= pos.x && x <= pos.x + size.x
		&& y >= pos.y && y <= pos.y + size.y) {
		
		this->isActive = !this->isActive;
		cout << "here" << endl;
	}
}

void Pompe::update() {
	if(this->isActive) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
}

void Pompe::render(Interface *interface) {
	this->circle.render(interface);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	if(!this->isMain) {
		this->button.render(interface->dashboard);
		draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
	}
}

