
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Moteur::Moteur(const char* name, const sf::Vector2f &st)
		:Module(name, st),
		box(sf::Vector2f(st.x - 5, st.y - 30), 45, 100, 5) {
	this->isFeed = false;
}

Moteur::~Moteur() {}

void Moteur::initReservoir(Reservoir *res) {
	this->reservoir = res;
}

void Moteur::addVanneNormal(VanneNormal *v) {
	this->vanne_normal.push_back(v);
}

void Moteur::setFeed(bool boolean) {
	this->isFeed = boolean;
}

void Moteur::update() {
	if(this->reservoir->checkfeed()) {
		this->isFeed = true;
		this->color = sf::Color::Green;
	}
	else {
		this->isFeed = false;
		this->color = sf::Color::Red;
	}
	this->box.setColor(this->color);
}


void Moteur::render(Interface *interface) {
	this->box.render(interface->statement);
	
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 30, sf::Color::Black);
}
