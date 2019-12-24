#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name, const sf::Vector2f &st, sf::Vector2f db)
		:name(name),
		pos_db(db),
		pos_st(st) {}

Module::~Module() {}

string &Module::getName() {
	return this->name;
}
