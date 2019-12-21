
#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

System::System():composant() {
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
	
	VanneTransi *vt12 = new VanneTransi("vt12");
	VanneTransi *vt23 = new VanneTransi("vt23");
	this->composant.push_back(vt12);
	this->composant.push_back(vt23);
	
	// Pompe
	Pompe *p11 = new Pompe("p11");
	Pompe *p12 = new Pompe("p12");
	this->composant.push_back(p11);
	this->composant.push_back(p12);
	
	tank1->initPompe(p11, p12);
	
	Pompe *p21 = new Pompe("p21");
	Pompe *p22 = new Pompe("p22");
	this->composant.push_back(p21);
	this->composant.push_back(p22);
	
	tank2->initPompe(p21, p22);
	
	Pompe *p31 = new Pompe("p31");
	Pompe *p32 = new Pompe("p32");
	this->composant.push_back(p31);
	this->composant.push_back(p32);
	
	tank3->initPompe(p31, p32);
	
	m1->initReservoir(tank1);
	m2->initReservoir(tank2);
	m3->initReservoir(tank3);
	
	tank1->initMoteur(m1);
	tank2->initMoteur(m2);
	tank3->initMoteur(m3);
	
	initVanne(tank1, vt12, tank2);
	initVanne(tank2, vt23, tank3);
}

System::~System() {
	for(Module* m : composant) {
		delete m;
	}
}

void System::initVanne(Reservoir *r1, VanneTransi *v, Reservoir *r2) {
	v->initReservoir(r1, r2);
	r1->initTransi(v);
	r2->initTransi(v);
}
