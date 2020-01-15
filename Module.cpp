#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(Utilisateur *user, const char* name, const sf::Vector2f &st)
		:name(name),
		pos_st(st) {

	this->user = user;
}

Module::~Module() {}

bool Module::getFeed() { return true; }
