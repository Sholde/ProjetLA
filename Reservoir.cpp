#include "Include.hh"
#include <vector>
#include <iostream>
using namespace std;

Reservoir::Reservoir(const char* name, int x, int y):Module(name, x, y) {
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
}

void Reservoir::render(Interface *interface) {
	sf::Text text(this->name, interface->font, 30);
	text.setPosition(this->point.getX(), this->point.getY());
	interface->window.draw(text);
}
