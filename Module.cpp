#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name, const sf::Vector2f &st, sf::Vector2f db, sf::Color color)
		:name(name),
		pos_db(db),
		pos_st(st),
		color(color) {}

Module::~Module() {}

string &Module::getName() {
	return this->name;
}
