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

void VanneTransi::render() {}

void VanneTransi::open() {
	if(!this->left->getFull() || !this->right->getFull()) {
		this->isOpen = !this->isOpen;
	}
}
