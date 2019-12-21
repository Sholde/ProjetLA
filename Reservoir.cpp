#include "Include.hh"

Reservoir::Reservoir(const char* name):Module(name) {
	
}

Reservoir::~Reservoir() {
	
}

void Reservoir::initMoteur(Moteur *mot) {
	this->moteur = mot;
}
