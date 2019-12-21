#include "Include.hh"

VanneTransi::VanneTransi(const char* name):Vanne(name) {
	
}

VanneTransi::~VanneTransi() {}

void VanneTransi::initReservoir(Reservoir *l, Reservoir *r) {
	this->right = r;
	this->left = l;
}
