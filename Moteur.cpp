#include "Include.hh"
#include <iostream>
using namespace std;

Moteur::Moteur(const char* name, int x, int y)
		:Module(name, x, y),
		pos_rect(x - 5, y - 30),
		size_rect(45.f, 100.f) {
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
}


void Moteur::render(Interface *interface) {
	draw_rectangle(interface->statement, this->pos_rect, this->size_rect, this->color);
	
	draw_text(interface->statement, this->pos_text, this->name, interface->font, 30, sf::Color::Black);
}
