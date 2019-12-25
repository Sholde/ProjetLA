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

void VanneNormal::checkFeed() {
	bool left = this->rl->getFeed() || this->vl->getFeed();
	bool right = this->rr->getFeed() || this->vr->getFeed();
	if(this->isOpen && (left ^ right)) {
		this->isFeed = true;
	}
	else {
		this->isFeed = false;
	}
}

void VanneNormal::update() {}

void VanneNormal::render() {}

void VanneNormal::open() {
	if(this->isOpen) {
		this->isOpen = false;
	}
	else {
		bool left = this->rl->getFeed() || this->vl->getFeed();
		bool right = this->rr->getFeed() || this->vr->getFeed();
		if(!(left && right))
			this->isOpen = true;
	}
	
	if(this->isOpen) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
}
