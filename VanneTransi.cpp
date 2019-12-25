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

void VanneTransi::share() {
	int capacity = (this->left->getCapacity() + this->right->getCapacity()) / 2;
	this->left->setCapacity(capacity);
	this->right->setCapacity(capacity);
}

void VanneTransi::update() {
	if(this->isOpen) {
		this->share();
	}
}

void VanneTransi::open() {
	if(this->isOpen) {
		this->isOpen = false;
	}
	else {
		this->isOpen = true;
	}
}
