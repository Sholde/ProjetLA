#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>
#include "Class.hh"

class Module {
	// private field
	private:
		sf::Text name;
	
	// public field
	public:
		Module(const char* name, sf::Font &font, int size = 30);
		~Module();
		
		sf::Text getText();
};

#endif
