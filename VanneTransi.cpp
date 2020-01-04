#include "Include.hh"
#include <iostream>
using namespace std;

VanneTransi::VanneTransi(Utilisateur *user, const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Vanne(user, name, st, db) {}

VanneTransi::~VanneTransi() {}

void VanneTransi::initReservoir(Reservoir *l, Reservoir *r) {
	this->right = r;
	this->left = l;
}

void VanneTransi::share() {
	if(this->left->getCapacity() > this->right->getCapacity()) {
		this->left->setCapacity(this->left->getCapacity() - this->flow);
		this->right->setCapacity(this->right->getCapacity() + this->flow);
	}
	else {
		this->left->setCapacity(this->left->getCapacity() + this->flow);
		this->right->setCapacity(this->right->getCapacity() - this->flow);
	}
}

void VanneTransi::update() {
	if(this->isOpen) {
		this->share();
	}
}

void VanneTransi::open() {
	if(this->isOpen) {
		this->isOpen = false;
		this->user->addHistory("fermeture de la vanne " + this->name);
	}
	else {
		this->isOpen = true;
		this->user->addHistory("ouverture de la vanne " + this->name);
	}
}
