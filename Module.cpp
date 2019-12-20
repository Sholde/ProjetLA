#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "Module.hh"

Module::Module(int test) {
	this->test = test;
}

Module::~Module() {}

int Module::getTest() { 
	return test;
}
