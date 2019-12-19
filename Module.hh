#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>

class Module {
	// private field
	int test;
	
	// public field
	public:
		Module(int test);
		~Module();

		
		int getTest() { return test; };
		
		//sf::Text getName() { return name; };
		
		virtual void update();
		virtual void render();
};

#endif
