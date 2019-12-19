#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>

class Module {
	// private field
	sf::Text name;
	
	// public field
	public:
		Module(const char* name);
		~Module();
		
		virtual void update() = 0;
		virtual void render() = 0;
};

#endif
