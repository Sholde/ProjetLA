#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(const char* name)
	:Module(name) {
	this->isActive = false;
	this->isFailure = false;
}

bool Pompe::getActive() {
	return this->isActive;
}

void Pompe::setActive(bool boolean) {
	this->isActive = boolean;
}

void Pompe::render() {
	;
}

