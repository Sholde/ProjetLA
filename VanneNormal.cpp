#include "Include.hh"
#include <iostream>
using namespace std;

VanneNormal::VanneNormal(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Vanne(name, st, db) {}

VanneNormal::~VanneNormal() {}

void VanneNormal::initLeft(Reservoir *r, VanneNormal *v, Moteur *m) {
	this->rl = r;
	this->vl = v;
	this->ml = m;
}

void VanneNormal::initRight(Reservoir *r, VanneNormal *v, Moteur *m) {
	this->rr = r;
	this->vr = v;
	this->mr = m;
}

bool VanneNormal::checkFeed(Reservoir *r1, Reservoir *r2) {
	if(this->isOpen) {
		if(!r2) {
			if(this->rl != r1) {
				if(this->rl->checkFeed()) {
					return true;
				}
				return this->vl->checkFeed(r1, rl);
			}
			else if(this->rr != r1) {
				if(this->rr->checkFeed()) {
					return true;
				}
				return this->vr->checkFeed(r1, rr);
			}
			else
				return false;
		}
		else {
			if(this->rl != r1 && this->rl != r2) {
				if(this->rl->checkFeed()) {
					return true;
				}
				return false;
			}
			else if(this->rr != r1  && this->rr != r2) {
				if(this->rr->checkFeed()) {
					return true;
				}
				return false;
			}
			else
				return false;
		}
	}
	return false;
}

void VanneNormal::update() {}

void VanneNormal::render() {}

void VanneNormal::open() {
	this->isOpen = !this->isOpen;
	
	if(this->isOpen) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
}
