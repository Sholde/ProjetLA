#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(Utilisateur *user, const char* name, const sf::Vector2f &st)
		:Module(user, name, st),
		circle(sf::Vector2f(st.x - st_pompe_x, st.y - st_pompe_y), st_pompe_radius, MARGIN),
		button(sf::Vector2f(0, 0), box_size_x, box_size_y, box_margin) {
	this->isActive = false;
	this->isFailure = false;
	this->isMain = true;
	this->mot = nullptr;
}

Pompe::Pompe(Utilisateur *user, const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(user, name, st),
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

bool Pompe::isTaken() {
	if(this->mot != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Pompe::take(Moteur* mot) {
	if(!mot->isTaken()) {
		this->mot = mot;
		this->mot->setPompe(this);
	}
}

void Pompe::clear() {
	this->mot = nullptr;
}

bool Pompe::calculCarburant(Moteur* mot) {
	if(!this->isFailure && this->isActive) {
		if(!this->isTaken()) {
			this->take(mot);
			return true;
		}
	}
	return false;
}

bool Pompe::checkFeed() {
	if(this->isFailure || !this->isActive) {
		return false;
	}
	else {
		return true;
	}
}

void Pompe::handleClicDashboard(int &x, int &y) {
	if(!this->isMain) {
		if(this->button.isClicOn(x, y)) {
			this->isActive = !this->isActive;
			if(this->isActive) {
				this->user->addHistory("ouverture de la pompe " + this->name);
			}
			else {
				this->user->addHistory("fermeture de la pompe " + this->name);
			}
		}
	}
}

void Pompe::handleClicStatement(int &x, int &y) {
	if(this->isClickOn(x, y)) {
		this->isFailure = true;
		this->isActive = false;
		this->user->addHistory("la pompe " + this->name + " tombe en panne");
		this->user->addRating(2);
	}
}

bool Pompe::isClickOn(int &x,int &y) {
	return this->circle.isClicOn(x, y);
}

void Pompe::update() {
}

void Pompe::render(Interface *interface) {
	if(this->isActive) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
	if(this->isFailure) {
		this->circle.setColor(sf::Color::Yellow);
	}
	
	this->circle.render(interface);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	if(!this->isMain) {
		this->button.render(interface->dashboard);
		draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
	}
}
