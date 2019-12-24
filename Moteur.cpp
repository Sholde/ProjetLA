
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Moteur::Moteur(const char* name, const sf::Vector2f &st)
		:Module(name, st),
		rect(sf::Vector2f(st.x - st_mot_x, st.y - st_mot_y), st_size_mot_x, st_size_mot_y, MARGIN) {
	this->isFeed = false;
}

Moteur::~Moteur() {}

void Moteur::initReservoir(Reservoir *res) {
	this->reservoir = res;
}

void Moteur::addVanneNormal(VanneNormal *v) {
	if(!this->v1)
		this->v1 = v;
	else if(!this->v2)
		this->v2 = v;
}

void Moteur::setFeed(bool boolean) {
	this->isFeed = boolean;
}

void Moteur::update() {
	if(this->reservoir->checkfeed()) {
		this->isFeed = true;
		this->rect.setColor(sf::Color::Green);
	}
	else {
		this->isFeed = false;
		this->rect.setColor(sf::Color::Red);
	}
}


void Moteur::render(Interface *interface) {
	this->rect.render(interface->statement);
	
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 30, sf::Color::Black);
}
