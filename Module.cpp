#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name, int x, int y, sf::Color color)
		:name(name),
		pos_text(x, y),
		color(color) {}

Module::~Module() {}

string &Module::getName() {
	return this->name;
}
