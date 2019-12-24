#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

Module::Module(const char* name, const sf::Vector2f &st)
		:name(name),
		pos_st(st) {}

Module::~Module() {}
