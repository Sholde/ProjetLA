#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name, int x, int y):name(name), point(x, y) {}

Module::~Module() {}

string &Module::getName() {
	return this->name;
}
