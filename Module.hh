#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

class Module {
	// private field
	protected:
		string name;
		sf::Vector2f pos_db;
		sf::Vector2f pos_st;
		sf::Color color;
	
	// public field
	public:
		Module(const char* name, const sf::Vector2f &st, sf::Vector2f = sf::Vector2f(0, 0), sf::Color = sf::Color::Red);
		~Module();
		
		string &getName();
		
		virtual void update() {};
		virtual void render(Interface *interface) {};
};

#endif
