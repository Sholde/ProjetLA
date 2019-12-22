#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name):name(name) {
}

Module::~Module() {}

string &Module::getName() {
	return this->name;
}
