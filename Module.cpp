#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name, sf::Vector2f pos, sf::Color color)
		:name(name),
		pos_text(pos),
		color(color) {}

Module::~Module() {}

string &Module::getName() {
	return this->name;
}
