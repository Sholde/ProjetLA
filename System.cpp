
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

System::System():composant() {
	sf::Vector2f vect;
	sf::Vector2f db;
	vect.x = WIDTH/6;
	vect.y = HEIGHT - HEIGHT/4;
	Moteur *m1 = new Moteur("m1", vect);
	vect.x = WIDTH/2;
	vect.y = HEIGHT - HEIGHT/4;
	Moteur *m2 = new Moteur("m2", vect);
	vect.x = WIDTH - WIDTH/6;
	vect.y = HEIGHT - HEIGHT/4;
	Moteur *m3 = new Moteur("m3", vect);
	this->composant.push_back(m1);
	this->composant.push_back(m2);
	this->composant.push_back(m3);
	
	vect.x = WIDTH/6 - 10;
	vect.y = HEIGHT/10 - 10;
	db.x = db_p12_x;
	db.y = db_p12_y;
	Reservoir *tank1 = new Reservoir("tank1", vect);
	vect.x = WIDTH/2 - 10;
	vect.y = HEIGHT/10 - 10;
	db.x = db_p22_x;
	db.y = db_p22_y;
	Reservoir *tank2 = new Reservoir("tank2", vect);
	vect.x = WIDTH - WIDTH/6 - 10;
	vect.y = HEIGHT/10 - 10;
	db.x = db_p32_x;
	db.y = db_p32_y;
	Reservoir *tank3 = new Reservoir("tank3", vect);
	this->composant.push_back(tank1);
	this->composant.push_back(tank2);
	this->composant.push_back(tank3);
	
	vect.x = WIDTH/3 + 15;
	vect.y = HEIGHT/10 - 10;
	db = vect;
	VanneTransi *vt12 = new VanneTransi("vt12", vect, db);
	vect.x = WIDTH - WIDTH/3 + 15;
	vect.y = HEIGHT/10 - 10;
	db = vect;
	VanneTransi *vt23 = new VanneTransi("vt23", vect, db);
	this->composant.push_back(vt12);
	this->composant.push_back(vt23);
	
	// Pompe
	vect.x = WIDTH/6 - 5;
	vect.y = HEIGHT/10;
	db.x = 0;
	db.y = 0;
	Pompe *p11 = new Pompe("p11", vect, db);
	vect.x = WIDTH/6 + 53;
	db.x = db_p12_x;
	db.y = db_p12_y;
	Pompe *p12 = new Pompe("p12", vect, db);
	this->composant.push_back(p11);
	this->composant.push_back(p12);
	
	tank1->initPompe(p11, p12);
	
	vect.x = WIDTH/2 - 5;
	db.x = 0;
	db.y = 0;
	Pompe *p21 = new Pompe("p21", vect, db);
	vect.x = WIDTH/2 + 53;
	db.x = db_p22_x;
	db.y = db_p22_y;
	Pompe *p22 = new Pompe("p22", vect, db);
	this->composant.push_back(p21);
	this->composant.push_back(p22);
	
	tank2->initPompe(p21, p22);
	
	vect.x = WIDTH - WIDTH/6 - 5;
	db.x = 0;
	db.y = 0;
	Pompe *p31 = new Pompe("p31", vect, db);
	vect.x = WIDTH - WIDTH/6 + 53;
	db.x = db_p32_x;
	db.y = db_p32_y;
	Pompe *p32 = new Pompe("p32", vect, db);
	this->composant.push_back(p31);
	this->composant.push_back(p32);
	
	tank3->initPompe(p31, p32);
	
	vect.x = WIDTH/3 + 15;
	vect.y = HEIGHT - HEIGHT/2;
	db.x = WIDTH/4;
	db.y = HEIGHT - HEIGHT/4;
	VanneNormal *v12 = new VanneNormal("v12",vect, db);
	vect.x = WIDTH - WIDTH/3 + 15;
	db.x = WIDTH/2;
	VanneNormal *v23 = new VanneNormal("v23", vect, db);
	vect.x = WIDTH/2 + 15;
	vect.y = HEIGHT/4;
	db.x = WIDTH - WIDTH/4;
	VanneNormal *v13 = new VanneNormal("v13", vect, db);
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

void createIssue() {
	;
}

void System::handleClic(int &x, int &y) {
	for(Module* m : composant) {
		m->handleClic(x, y);
	}
}

void System::update() {
	for(Module* m : composant) {
		m->update();
	}
}

void System::render(Interface *interface) {
	for(Module* m : composant) {
		m->render(interface);
	}
}
