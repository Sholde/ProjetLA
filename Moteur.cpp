#include "Include.hh"
#include <iostream>
using namespace std;

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

void Moteur::render() {
	cout << this->name << " : " << this->reservoir->getName() << endl;
}
