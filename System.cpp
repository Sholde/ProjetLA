
#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

System::System() {
	Moteur *m1 = new Moteur("m1");
	Moteur *m2 = new Moteur("m2");
	Moteur *m3 = new Moteur("m3");
	this->composant.push_back(m1);
	this->composant.push_back(m2);
	this->composant.push_back(m3);
	
	Reservoir *tank1 = new Reservoir("tank1");
	Reservoir *tank2 = new Reservoir("tank2");
	Reservoir *tank3 = new Reservoir("tank3");
	this->composant.push_back(tank1);
	this->composant.push_back(tank2);
	this->composant.push_back(tank3);
	
	m1->initReservoir(tank1);
	m2->initReservoir(tank2);
	m3->initReservoir(tank3);
	
	tank1->initMoteur(m1);
	tank2->initMoteur(m2);
	tank3->initMoteur(m3);
	
	cout << m1->getReservoir()->getName() << endl;
}

System::~System() {
	for(Module* m : composant) {
		delete m;
	}
}
