#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

Vanne::Vanne(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, sf::Vector2f(st.x - 15, st.y + 40), db),
		box(sf::Vector2f(db.x - 30, db.y), 100, 40, 5),
		box_circle(sf::Vector2f(st.x - 22.5, st.y + 30), 28, 5) {
	this->isOpen = false;
}

Vanne::~Vanne() {}

bool Vanne::getOpen() {
	return this->isOpen;
}

void Vanne::handleClic(int &x, int &y) {
	sf::Vector2f pos = this->box.getPoint();
	sf::Vector2f size = this->box.getSize();
	
	if(x >= pos.x && x <= pos.x + size.x
		&& y >= pos.y && y <= pos.y + size.y) {
		
		this->isOpen = !this->isOpen;
	}
}

void Vanne::update() {
	if(this->isOpen) {
		this->color = sf::Color::Green;
	}
	else {
		this->color = sf::Color::Red;
	}
	this->box_circle.setColor(this->color);
}

void Vanne::render(Interface *interface) {
	this->box_circle.render(interface);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	this->box.render(interface->dashboard);
	draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
}
