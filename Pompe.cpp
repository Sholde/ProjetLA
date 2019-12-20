#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "Module.hh"
#include "Pompe.hh"

Pompe::Pompe(const char* name, sf::Font &font)
	:Module(name, font) {
	this->isActive = false;
}
