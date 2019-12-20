#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "Module.hh"

Module::Module(const char* name, sf::Font &font, int size)
	:name(name, font, size) {
}

Module::~Module() {}

sf::Text Module::getText() {
	return this->name;
}
