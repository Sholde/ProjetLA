#include "Include.hh"

Vanne::Vanne(const char* name):Module(name) {
	this->isOpen = false;
}

Vanne::~Vanne() {}

bool Vanne::getOpen() {
	return this->isOpen;
}
