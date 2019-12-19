#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>

class Module {
	// private field
	sf::Text name;
	
	// public field
	public:
		Module(const char* name, sf::Font *font);
		~Module();
		
		sf::Text getName() { return name; };
		
		virtual void update();
		virtual void render();
};

#endif
