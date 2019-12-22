#include "Include.hh"
#include <iostream>
using namespace std;

VanneTransi::VanneTransi(const char* name):Vanne(name) {
	
}

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
