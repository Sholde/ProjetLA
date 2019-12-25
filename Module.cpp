#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name, const sf::Vector2f &st)
		:name(name),
		pos_st(st) {
	
	this->isFeed = false;
}

Module::~Module() {}


bool &Module::getFeed() {
	return this->isFeed;
}
