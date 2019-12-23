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
		sf::Vector2f pos_text;
		sf::Color color;
	
	// public field
	public:
		Module(const char* name, int = 0, int = 0, sf::Color = sf::Color::Red);
		~Module();
		
		string &getName();
		
		virtual void update() {};
		virtual void render(Interface *interface) {};
};

#endif
