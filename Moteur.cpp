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

void Moteur::addVanneNormal(VanneNormal *v) {
	this->vanne_normal.push_back(v);
}

void Moteur::render() {
	cout << this->name << " : " << this->reservoir->getName() << " ";
	for(Vanne* v : vanne_normal) {
		cout << v->getName() << " ";
	}
	cout << endl;
}
