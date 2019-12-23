#include "Include.hh"
#include <iostream>
using namespace std;

VanneTransi::VanneTransi(const char* name, sf::Vector2f pos)
		:Vanne(name, pos) {}

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

void VanneTransi::render() {
	cout << this->getName() << " : " << this->left->getName() << " " << this->right->getName() << endl;
}
