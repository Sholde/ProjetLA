#include <iostream>
#include "Module.h"

Module::Module(string nom):nom(nom) {}

Module::~Module() {}

ostream& operator<<(ostream& out, Module& module) {
	out << module.nom << endl;
	return out;
}
