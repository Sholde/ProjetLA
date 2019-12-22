#include "Include.hh"
#include <iostream>
using namespace std;

Moteur::Moteur(const char* name):Module(name) {
	this->isFeed = false;
}

Moteur::~Moteur() {
	
}

void Moteur::initReservoir(Reservoir *res) {
	this->reservoir = res;
}

void Moteur::addVanneNormal(VanneNormal *v) {
	this->vanne_normal.push_back(v);
}

void Moteur::update() {
	if(this->reservoir->checkfeed())
		this->isFeed = true;
	else
		this->isFeed = false;
	cout << " update  " << this->isFeed << endl;
}


void Moteur::render() {
	cout << this->name << " : " << this->reservoir->getName() << " ";
	for(Vanne* v : vanne_normal) {
		cout << v->getName() << " ";
	}
	cout << endl;
}
