#include "Include.hh"
#include <iostream>
using namespace std;

VanneTransi::VanneTransi(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Vanne(name, st, db) {}

VanneTransi::~VanneTransi() {}

void VanneTransi::initReservoir(Reservoir *l, Reservoir *r) {
	this->right = r;
	this->left = l;
}

Reservoir *VanneTransi::getLeft() {
	return this->left;
}

Reservoir *VanneTransi::getRight() {
	return this->right;
}

void VanneTransi::share() {
	int capacity = (this->left->getCapacity() + this->right->getCapacity()) / 2;
	this->left->setCapacity(capacity);
	this->right->setCapacity(capacity);
}

void VanneTransi::update() {
	if(this->isOpen) {
		this->share();
	}
	
	if(this->isOpen) {
		this->circle.setColor(sf::Color::Green);
	}
	else {
		this->circle.setColor(sf::Color::Red);
	}
}

void VanneTransi::render() {}

void VanneTransi::open() {
	if(this->isOpen) {
		this->isOpen = false;
	}
	else {
		this->share();
		this->isOpen = true;
	}
}
