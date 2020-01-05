
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Moteur::Moteur(Utilisateur *user, const char* name, const sf::Vector2f &st)
		:Module(user, name, st),
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

void Moteur::checkFeed() {
	if(this->reservoir->checkFeed() || this->v1->checkFeed() || this->v2->checkFeed()) {
		if(!this->isFeed) {
			this->user->addHistory("le moteur " + this->name + " est désormais alimenté");
		}
		this->isFeed = true;
	}
	else {
		if(this->isFeed) {
			this->user->addHistory("le moteur " + this->name + " n'est plus alimenté");
		}
		this->isFeed = false;
	}
}

bool Moteur::getFeed() {
	return this->isFeed;
}

void Moteur::update() {
	this->checkFeed();
}


void Moteur::render(Interface *interface) {
	if(this->isFeed) {
		this->rect.setColor(sf::Color::Green);
	}
	else {
		this->rect.setColor(sf::Color::Red);
	}
	
	this->rect.render(interface->statement);
	
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 30, sf::Color::Black);
}
