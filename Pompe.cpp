#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Pompe::Pompe(const char* name)
	:Module(name) {
	this->isActive = false;
	this->isFailure = false;
}

void Pompe::render() {
	;
}

