#include "Include.hh"
#include <vector>
#include <iostream>
using namespace std;

Reservoir::Reservoir(const char* name, int capacity, const sf::Vector2f &st)
		:Module(name, st),
		rect(sf::Vector2f(st.x - st_res_x, st.y - st_res_y), st_size_res_x, st_size_res_y, MARGIN) {
	this->capacity = capacity;
	if(this->capacity > 0)
		this->isFull = true;
	else
		this->isFull = false;
}

Reservoir::~Reservoir() {}

int &Reservoir::getCapacity() {
	return this->capacity;
}

void Reservoir::setCapacity(int &capacity) {
	this->capacity = capacity;
}

void Reservoir::initMoteur(Moteur *mot) {
	this->moteur = mot;
}

void Reservoir::addVanneTransi(VanneTransi *v) {
	this->vanne_transi.push_back(v);
}

void Reservoir::initPompe(Pompe *m, Pompe *s) {
	this->main = m;
	// tmp
	// this->main->setActive();
	this->main->setIsMain();
	this->second = s;
}

void Reservoir::addVanneNormal(VanneNormal *v) {
	this->vanne_normal.push_back(v);
}

bool Reservoir::checkPompe() {
	return this->main->checkFeed() || this->second->checkFeed();
}

bool Reservoir::checkFeed() {
	if(this->capacity > 0 && this->checkPompe())
		return true;
	else
		return false;
}

bool Reservoir::getFull() {
	return this->isFull;
}

void Reservoir::setFull(bool boolean) {
	this->isFull = boolean;
}

void Reservoir::update() {
	
	if(this->checkFeed()) {
		this->isFull = true;
	}
	
	if(this->capacity > 0) {
		this->capacity--;
	}
	else
		this->isFull = false;
	
	if(this->isFull) {
		this->rect.setColor(sf::Color::Green);
	}
	else {
		this->rect.setColor(sf::Color::Red);
	}
}

void Reservoir::render(Interface *interface) {
	this->rect.render(interface->statement);
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 30, sf::Color::Black);
	
	this->main->render(interface);
	this->second->render(interface);
}
