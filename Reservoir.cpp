#include "Include.hh"
#include <vector>
#include <iostream>
using namespace std;

Reservoir::Reservoir(const char* name, const sf::Vector2f &st)
		:Module(name, st),
		pos_rect(st.x - 25, st.y - 20),
		size_rect(120.f, 130.f) {
	this->isFull = true;
}

Reservoir::~Reservoir() {}

void Reservoir::initMoteur(Moteur *mot) {
	this->moteur = mot;
}

void Reservoir::addVanneTransi(VanneTransi *v) {
	this->vanne_transi.push_back(v);
}

void Reservoir::initPompe(Pompe *m, Pompe *s) {
	this->main = m;
	this->main->setActive(true);
	this->main->setIsMain();
	this->second = s;
}

void Reservoir::addVanneNormal(VanneNormal *v) {
	this->vanne_normal.push_back(v);
}

bool Reservoir::checkPompe() {
	return this->main->getActive() || this->second->getActive();
}

bool Reservoir::checkfeed() {
	if(this->isFull && this->checkPompe())
		return true;
	return false;
}

void Reservoir::setFull(bool boolean) {
	this->isFull = boolean;
}

void Reservoir::update() {
	if(!this->isFull) {
		for(VanneTransi* v : vanne_transi) {
			if(v->getOpen()) {
				if(v->getLeft() != this && v->getLeft()->isFull)
					this->isFull = true;
				if(v->getRight() != this && v->getRight()->isFull)
					this->isFull = true;
			}
		}
	}
	
	if(this->isFull) {
		this->color = sf::Color::Green;
	}
	else {
		this->color = sf::Color::Red;
	}
	
	this->main->update();
	this->second->update();
}

void Reservoir::render(Interface *interface) {
	draw_rectangle(interface->statement, this->pos_rect, this->size_rect, this->color);
	
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 30, sf::Color::Black);
	
	this->main->render(interface);
	this->second->render(interface);
}
