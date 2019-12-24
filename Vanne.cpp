#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

Vanne::Vanne(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, sf::Vector2f(st.x - 15, st.y + 40)),
		button(sf::Vector2f(db.x - 30, db.y), 100, 40, 5),
		circle(sf::Vector2f(st.x - 22.5, st.y + 30), 28, 5),
		pos_db(db) {
	this->isOpen = false;
}

Vanne::~Vanne() {}

bool Vanne::getOpen() {
	return this->isOpen;
}

void Vanne::handleClic(int &x, int &y) {
	sf::Vector2f pos = this->button.getPoint();
	sf::Vector2f size = this->button.getSize();
	
	if(x >= pos.x && x <= pos.x + size.x
		&& y >= pos.y && y <= pos.y + size.y) {
		
		this->isOpen = !this->isOpen;
	}
}

void Vanne::update() {
	if(this->isOpen) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
}

void Vanne::render(Interface *interface) {
	this->circle.render(interface);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	this->button.render(interface->dashboard);
	draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
}
