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
		return this->rl->cF(mot);
	}
	else if(this->rr != res1) {
		return this->rr->cF(mot);
	}
	else
		return false;
}

bool VanneNormal::caseTwoRes(Reservoir *res1, Moteur *mot, Reservoir *res2) {
	if(this->rl != res1 && this->rl != res2) {
		return this->rl->cF(mot);
	}
	else if(this->rr != res1 && this->rr != res2) {
		return this->rr->cF(mot);
	}
	else
		return false;
}

bool VanneNormal::checkFeed() {
	return this->allPompeIsActive();
}

bool VanneNormal::cF(Reservoir *res1, Moteur *mot, Reservoir *res2) {
	if(!this->isOpen)
		return false;
		
	if(!res2) {
		if(caseOneRes(res1, mot)) {
			return true;
		}
		else {
			if(this->rr == res1)
				return this->vl->cF(res1, mot, rl);
			else
				return this->vr->cF(res1, mot, rr);
		}
	}
	else {
		return caseTwoRes(res1, mot, res2);
	}
}

bool VanneNormal::noPompeIsActive() {
	return !(this->rl->checkPompe() || this->rr->checkPompe());
}

bool VanneNormal::allPompeIsActive() {
	bool left = this->rl->checkFeed();
	bool right = this->rr->checkFeed();
	if(left) {
		if(this->rl->checkAllPompe()) {
			return true;
		}
		return false;
	}
	else if(right) {
		if(this->rr->checkAllPompe()) {
			return true;
		}
		return false;
	}
	return false;
}

bool VanneNormal::isComming2side() {
	bool left = this->rl->checkFeed();
	bool right = this->rr->checkFeed();
	return left && right;
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
