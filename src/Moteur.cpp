
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Moteur::Moteur(Utilisateur *user, const char* name, const sf::Vector2f &st)
		:Module(user, name, st),
		rect(sf::Vector2f(st.x - st_mot_x, st.y - st_mot_y), st_size_mot_x, st_size_mot_y, MARGIN) {
	this->v1 = nullptr;
	this->v2 = nullptr;
	this->isFeed = false;
	this->pompe = nullptr;
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

bool Moteur::isTaken() {
	if(this->pompe) {
		return true;
	}
	else {
		return false;
	}
}

void Moteur::clear() {
	this->pompe = nullptr;
}

void Moteur::setPompe(Pompe* p) {
	this->pompe = p;
}

void Moteur::calculCarburant() {
	this->reservoir->calculCarburant(this) || this->v1->calculCarburant(this->reservoir, this)  || this->v2->calculCarburant(this->reservoir, this);
}

bool Moteur::getFeed() {
	return this->isFeed;
}

void Moteur::update() {
	this->calculCarburant();
	if(this->pompe) {
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
