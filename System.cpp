
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

System::System():composant() {
	sf::Vector2f vect;
	sf::Vector2f db;
	vect.x = st_m1_x;
	vect.y = st_m1_y;
	Moteur *m1 = new Moteur("m1", vect);
	vect.x = st_m2_x;
	vect.y = st_m2_y;
	Moteur *m2 = new Moteur("m2", vect);
	vect.x = st_m3_x;
	vect.y = st_m3_y;
	Moteur *m3 = new Moteur("m3", vect);
	this->composant.push_back(m1);
	this->composant.push_back(m2);
	this->composant.push_back(m3);
	
	vect.x = st_tank1_x;
	vect.y = st_tank1_y;
	db.x = db_p12_x;
	db.y = db_p12_y;
	Reservoir *tank1 = new Reservoir("tank1", 1000, vect);
	vect.x = st_tank2_x;
	vect.y = st_tank2_y;
	db.x = db_p22_x;
	db.y = db_p22_y;
	Reservoir *tank2 = new Reservoir("tank2", 500, vect);
	vect.x = st_tank3_x;
	vect.y = st_tank3_y;
	db.x = db_p32_x;
	db.y = db_p32_y;
	Reservoir *tank3 = new Reservoir("tank3", 1000, vect);
	this->composant.push_back(tank1);
	this->composant.push_back(tank2);
	this->composant.push_back(tank3);
	
	vect.x = st_vt12_x;
	vect.y = st_vt12_y;
	db = vect;
	VanneTransi *vt12 = new VanneTransi("vt12", vect, db);
	vect.x = st_vt23_x;
	vect.y = st_vt23_y;
	db = vect;
	VanneTransi *vt23 = new VanneTransi("vt23", vect, db);
	this->composant.push_back(vt12);
	this->composant.push_back(vt23);
	
	// Pompe
	vect.x = st_p11_x;
	vect.y = st_p11_y;
	Pompe *p11 = new Pompe("p11", vect);
	vect.x = st_p12_x;
	vect.y = st_p12_y;
	db.x = db_p12_x;
	db.y = db_p12_y;
	Pompe *p12 = new Pompe("p12", vect, db);
	this->composant.push_back(p11);
	this->composant.push_back(p12);
	
	tank1->initPompe(p11, p12);
	
	vect.x = st_p21_x;
	vect.y = st_p21_y;
	Pompe *p21 = new Pompe("p21", vect);
	vect.x = st_p22_x;
	vect.y = st_p22_y;
	db.x = db_p22_x;
	db.y = db_p22_y;
	Pompe *p22 = new Pompe("p22", vect, db);
	this->composant.push_back(p21);
	this->composant.push_back(p22);
	
	tank2->initPompe(p21, p22);
	
	vect.x = st_p31_x;
	vect.y = st_p31_y;
	Pompe *p31 = new Pompe("p31", vect);
	vect.x = st_p32_x;
	vect.y = st_p32_y;
	db.x = db_p32_x;
	db.y = db_p32_y;
	Pompe *p32 = new Pompe("p32", vect, db);
	this->composant.push_back(p31);
	this->composant.push_back(p32);
	
	tank3->initPompe(p31, p32);
	
	vect.x = st_v12_x;
	vect.y = st_v12_y;
	db.x = db_v12_x;
	db.y = db_v12_y;
	VanneNormal *v12 = new VanneNormal("v12",vect, db);
	vect.x = st_v23_x;
	vect.y = st_v23_y;
	db.x = db_v23_x;
	db.y = db_v23_y;
	VanneNormal *v23 = new VanneNormal("v23", vect, db);
	vect.x = st_v13_x;
	vect.y = st_v13_y;
	db.x = db_v13_x;
	db.y = db_v13_y;
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
