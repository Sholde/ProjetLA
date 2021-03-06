#include "Include.hh"
#include <iostream>
using namespace std;

VanneNormal::VanneNormal(Utilisateur *user, const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Vanne(user, name, st, db) {}

VanneNormal::~VanneNormal() {}

void VanneNormal::initLeft(Reservoir *r, VanneNormal *v, Moteur *m) {
	this->rl = r;
	this->vl = v;
	this->ml = m;
}

void VanneNormal::initRight(Reservoir *r, VanneNormal *v, Moteur *m) {
	this->rr = r;
	this->vr = v;
	this->mr = m;
}

bool VanneNormal::caseOneRes(Reservoir *res1, Moteur *mot) {
	if(this->rl != res1) {
		return this->rl->calculCarburant(mot);
	}
	else if(this->rr != res1) {
		return this->rr->calculCarburant(mot);
	}
	else
		return false;
}

bool VanneNormal::caseTwoRes(Reservoir *res1, Moteur *mot, Reservoir *res2) {
	if(this->rl != res1 && this->rl != res2) {
		return this->rl->calculCarburant(mot);
	}
	else if(this->rr != res1 && this->rr != res2) {
		return this->rr->calculCarburant(mot);
	}
	else
		return false;
}

bool VanneNormal::calculCarburant(Reservoir *res1, Moteur *mot, Reservoir *res2) {
	if(!this->isOpen)
		return false;
		
	if(!res2) {
		if(caseOneRes(res1, mot)) {
			return true;
		}
		else {
			if(this->rr == res1)
				return this->vl->calculCarburant(res1, mot, rl);
			else
				return this->vr->calculCarburant(res1, mot, rr);
		}
	}
	else {
		return caseTwoRes(res1, mot, res2);
	}
}

void VanneNormal::update() {}

void VanneNormal::open() {
	if(this->isOpen) {
		this->isOpen = false;
		this->user->addHistory("fermeture de la vanne " + this->name);
	}
	else {
		this->isOpen = true;
		this->user->addHistory("ouverture de la vanne " + this->name);
	}
}
