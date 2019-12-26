#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

Vanne::Vanne(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, st),
		button(sf::Vector2f(db.x - db_decal, db.y), box_size_x, box_size_y, box_margin),
		circle(sf::Vector2f(st.x - st_vanne_x, st.y - st_vanne_y), st_vanne_radius, MARGIN),
		pos_db(db) {
	this->isOpen = false;
}

Vanne::~Vanne() {}

bool Vanne::getOpen() {
	return this->isOpen;
}

void Vanne::handleClicDashboard(int &x, int &y) {
	if(this->button.isClicOn(x, y)) {
		this->open();
	}
}

void Vanne::render(Interface *interface) {
	if(this->isOpen) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
	
	this->circle.render(interface);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	this->button.render(interface->dashboard);
	draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
}
