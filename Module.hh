#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>

class Module {
	// private field
	
	// public field
	public:
	int test;
		Module(int test);
		~Module();
		
		//sf::Text getName() { return name; };
		
		virtual void update();
		virtual void render();
};

#endif
