#include "Include.hh"

Moteur::Moteur(const char* name):Module(name) {
	
}

Moteur::~Moteur() {
	
}

void Moteur::initReservoir(Reservoir *res) {
	this->reservoir = res;
}

Reservoir *Moteur::getReservoir() {
	return this->reservoir;
}
