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

//~ bool VanneNormal::caseOneRes(Reservoir *r1) {
	//~ if(this->rl != r1) {
		//~ if(this->rl->checkFeed()) {
			//~ return true;
		//~ }
		//~ return this->vl->checkFeed(r1, rl) || this->vr->checkFeed(r1, rl);
	//~ }
	//~ else if(this->rr != r1) {
		//~ if(this->rr->checkFeed()) {
			//~ return true;
		//~ }
		//~ return this->vl->checkFeed(r1, rr) || this->vr->checkFeed(r1, rr);
	//~ }
	//~ else
		//~ return false;
//~ }

//~ bool VanneNormal::caseTwoRes(Reservoir *r1, Reservoir *r2) {
	//~ if(this->rl != r1 && this->rl != r2) {
		//~ if(this->rl->checkFeed()) {
			//~ return true;
		//~ }
		//~ return false;
	//~ }
	//~ else if(this->rr != r1  && this->rr != r2) {
		//~ if(this->rr->checkFeed()) {
			//~ return true;
		//~ }
		//~ return false;
	//~ }
	//~ else
		//~ return false;
//~ }

bool VanneNormal::checkFeed() {
	return this->allPompeIsActive();
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
