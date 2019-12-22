#include "Include.hh"

Vanne::Vanne(const char* name, int x, int y):Module(name, x, y) {
	this->isOpen = false;
}

Vanne::~Vanne() {}

bool Vanne::getOpen() {
	return this->isOpen;
}
