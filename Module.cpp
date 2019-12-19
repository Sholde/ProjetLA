#include <SFML/Graphics.hpp>
#include "Module.hh"

Module::Module(const char* name, sf::Font *font):name(name, *font, 30) {}

Module::~Module() {};
