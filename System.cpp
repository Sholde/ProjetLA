
#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

System::System():composant() {
	Moteur *m1 = new Moteur("m1", WIDTH/6, HEIGHT - HEIGHT/4);
	Moteur *m2 = new Moteur("m2", WIDTH/2, HEIGHT - HEIGHT/4);
	Moteur *m3 = new Moteur("m3", WIDTH - WIDTH/6, HEIGHT - HEIGHT/4);
	this->composant.push_back(m1);
	this->composant.push_back(m2);
	this->composant.push_back(m3);
	
	Reservoir *tank1 = new Reservoir("tank1", WIDTH/6 - 10, HEIGHT/10 - 10);
	Reservoir *tank2 = new Reservoir("tank2", WIDTH/2 - 10, HEIGHT/10 - 10);
	Reservoir *tank3 = new Reservoir("tank3", WIDTH - WIDTH/6 - 10, HEIGHT/10 - 10);
	this->composant.push_back(tank1);
	this->composant.push_back(tank2);
	this->composant.push_back(tank3);
	
	VanneTransi *vt12 = new VanneTransi("vt12");
	VanneTransi *vt23 = new VanneTransi("vt23");
	this->composant.push_back(vt12);
	this->composant.push_back(vt23);
	
	// Pompe
	Pompe *p11 = new Pompe("p11", WIDTH/6 - 5, HEIGHT/10);
	Pompe *p12 = new Pompe("p12", WIDTH/6 + 53, HEIGHT/10);
	this->composant.push_back(p11);
	this->composant.push_back(p12);
	
	tank1->initPompe(p11, p12);
	
	Pompe *p21 = new Pompe("p21", WIDTH/2 - 5, HEIGHT/10);
	Pompe *p22 = new Pompe("p22", WIDTH/2 + 53, HEIGHT/10);
	this->composant.push_back(p21);
	this->composant.push_back(p22);
	
	tank2->initPompe(p21, p22);
	
	Pompe *p31 = new Pompe("p31", WIDTH - WIDTH/6 - 5, HEIGHT/10);
	Pompe *p32 = new Pompe("p32", WIDTH - WIDTH/6 + 53, HEIGHT/10);
	this->composant.push_back(p31);
	this->composant.push_back(p32);
	
	tank3->initPompe(p31, p32);
	
	VanneNormal *v12 = new VanneNormal("v12");
	VanneNormal *v23 = new VanneNormal("v23");
	VanneNormal *v13 = new VanneNormal("v13");
	this->composant.push_back(v12);
	this->composant.push_back(v23);
	this->composant.push_back(v13);
	
	m1->initReservoir(tank1);
	m2->initReservoir(tank2);
	m3->initReservoir(tank3);
	
	tank1->initMoteur(m1);
	tank2->initMoteur(m2);
	tank3->initMoteur(m3);
	
	initVanne(tank1, vt12, tank2);
	initVanne(tank2, vt23, tank3);
	initVanne(tank1, tank2, v13, v12, v23, m1, m2);
	initVanne(tank2, tank3, v12, v23, v13, m2, m3);
	initVanne(tank1, tank3, v12, v13, v23, m1, m3);
}

System::~System() {
	for(Module* m : composant) {
		delete m;
	}
}

void System::initVanne(Reservoir *r1, VanneTransi *v, Reservoir *r2) {
	v->initReservoir(r1, r2);
	r1->addVanneTransi(v);
	r2->addVanneTransi(v);
}

void System::initVanne(Reservoir *r1, Reservoir *r2, VanneNormal *v1, VanneNormal *middle, VanneNormal *v2, Moteur *m1, Moteur * m2) {
	middle->initLeft(r1, v1, m1);
	middle->initRight(r2, v2, m2);
	r1->addVanneNormal(middle);
	r2->addVanneNormal(middle);
	m1->addVanneNormal(middle);
	m2->addVanneNormal(middle);
}

void System::update() {
	for(Module* m : composant) {
		if(dynamic_cast<Moteur*>(m))
			m->update();
		else if(dynamic_cast<Reservoir*>(m))
			m->update();
	}
}


void System::render(Interface *interface) {
	for(Module* m : composant) {
		if(dynamic_cast<Moteur*>(m))
			m->render(interface);
		else if(dynamic_cast<Reservoir*>(m))
			m->render(interface);
	}
}
