#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(Utilisateur *user, const char* name, const sf::Vector2f &st)
		:name(name),
		line(),
		pos_st(st) {

	this->user = user;
}

Module::~Module() {}

bool Module::getFeed() { return true; }

sf::Vector2f &Module::getPos() {
	return this->pos_st;
}

void Module::setLine(sf::Vector2f v1, sf::Vector2f v2, sf::Color color) {
	this->line[0].position = v1;
	this->line[0].color  = color;
	this->line[1].position = v2;
	this->line[1].color = color;
}
