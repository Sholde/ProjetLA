#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
#include <string>
using namespace std;

Module::Module(const char* name):name(name) {
	cout << this->name << endl;
}

Module::~Module() {}

string &Module::getName() {
	return this->name;
}
