
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

System::System(Utilisateur *user):composant() {
	sf::Vector2f vect;
	sf::Vector2f db;
	vect.x = st_m1_x;
	vect.y = st_m1_y;
	Moteur *m1 = new Moteur(user, "m1", vect);
	vect.x = st_m2_x;
	vect.y = st_m2_y;
	Moteur *m2 = new Moteur(user, "m2", vect);
	vect.x = st_m3_x;
	vect.y = st_m3_y;
	Moteur *m3 = new Moteur(user, "m3", vect);
	
	vect.x = st_tank1_x;
	vect.y = st_tank1_y;
	db.x = db_p12_x;
	db.y = db_p12_y;
	Reservoir *tank1 = new Reservoir(user, "tank1", cap_1_max, vect);
	vect.x = st_tank2_x;
	vect.y = st_tank2_y;
	db.x = db_p22_x;
	db.y = db_p22_y;
	Reservoir *tank2 = new Reservoir(user, "tank2", cap_2_max, vect);
	vect.x = st_tank3_x;
	vect.y = st_tank3_y;
	db.x = db_p32_x;
	db.y = db_p32_y;
	Reservoir *tank3 = new Reservoir(user, "tank3", cap_1_max, vect);
	
	vect.x = st_vt12_x;
	vect.y = st_vt12_y;
	db.x = db_vt12_x;
	db.y = db_vt12_y;
	VanneTransi *vt12 = new VanneTransi(user, "vt12", vect, db);
	vect.x = st_vt23_x;
	vect.y = st_vt23_y;
	db.x = db_vt23_x;
	db.y = db_vt23_y;
	VanneTransi *vt23 = new VanneTransi(user, "vt23", vect, db);
	
	// Pompe
	vect.x = st_p11_x;
	vect.y = st_p11_y;
	Pompe *p11 = new Pompe(user, "p11", vect);
	vect.x = st_p12_x;
	vect.y = st_p12_y;
	db.x = db_p12_x;
	db.y = db_p12_y;
	Pompe *p12 = new Pompe(user, "p12", vect, db);
	
	vect.x = st_p21_x;
	vect.y = st_p21_y;
	Pompe *p21 = new Pompe(user, "p21", vect);
	vect.x = st_p22_x;
	vect.y = st_p22_y;
	db.x = db_p22_x;
	db.y = db_p22_y;
	Pompe *p22 = new Pompe(user, "p22", vect, db);
	
	vect.x = st_p31_x;
	vect.y = st_p31_y;
	Pompe *p31 = new Pompe(user, "p31", vect);
	vect.x = st_p32_x;
	vect.y = st_p32_y;
	db.x = db_p32_x;
	db.y = db_p32_y;
	Pompe *p32 = new Pompe(user, "p32", vect, db);
	
	vect.x = st_v12_x;
	vect.y = st_v12_y;
	db.x = db_v12_x;
	db.y = db_v12_y;
	VanneNormal *v12 = new VanneNormal(user, "v12",vect, db);
	vect.x = st_v23_x;
	vect.y = st_v23_y;
	db.x = db_v23_x;
	db.y = db_v23_y;
	VanneNormal *v23 = new VanneNormal(user, "v23", vect, db);
	vect.x = st_v13_x;
	vect.y = st_v13_y;
	db.x = db_v13_x;
	db.y = db_v13_y;
	VanneNormal *v13 = new VanneNormal(user, "v13", vect, db);
	
	// Init liste
	
	this->composant.push_back(tank1);
	this->composant.push_back(tank2);
	this->composant.push_back(tank3);
	
	this->composant.push_back(vt12);
	this->composant.push_back(vt23);
	
	this->composant.push_back(p11);
	this->composant.push_back(p12);
	
	this->composant.push_back(p21);
	this->composant.push_back(p22);
	
	this->composant.push_back(p31);
	this->composant.push_back(p32);
	
	this->composant.push_back(v12);
	this->composant.push_back(v23);
	this->composant.push_back(v13);
	
	this->composant.push_back(m1);
	this->composant.push_back(m2);
	this->composant.push_back(m3);
	
	tank1->initPompe(p11, p12);
	tank2->initPompe(p21, p22);
	tank3->initPompe(p31, p32);
	
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

bool System::checkMoteur() {
	bool boolean = true;
	for(Module *m : composant) {
		boolean = boolean && m->getFeed();
	}
	return boolean;
}

void System::handleClicStatement(int &x, int &y) {
	for(Module *m : composant) {
		m->handleClicStatement(x, y);
	}
}

void System::handleClicDashboard(int &x, int &y) {
	for(Module *m : composant) {
		m->handleClicDashboard(x, y);
	}
}

void System::update() {
	for(Module *m : composant) {
		m->clear();
	}
	for(Module *m : composant) {
		m->update();
	}
}

void System::render(Interface *interface) {
	for(Module *m : composant) {
		m->render(interface);
	}
}
