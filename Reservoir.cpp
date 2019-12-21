#include "Include.hh"
#include <vector>
#include <iostream>
using namespace std;

Reservoir::Reservoir(const char* name):Module(name) {
	
}

Reservoir::~Reservoir() {
	
}

void Reservoir::initMoteur(Moteur *mot) {
	this->moteur = mot;
}

void Reservoir::initTransi(VanneTransi* v) {
	this->vanne_transi.push_back(v);
}

void Reservoir::initPompe(Pompe *m, Pompe *s) {
	this->main = m;
	this->second = s;
}


void Reservoir::render() {
	cout << this->name << " : " << this->moteur->getName() << " " << this->main->getName() << " " << this->second->getName() << " ";
	for(Vanne* v : vanne_transi) {
		cout << v->getName() << " ";
	}
	cout << endl;
}
