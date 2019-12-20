#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>
#include "Class.hh"

class Module {
	// private field
	private:
		int test;
	
	// public field
	public:
		Module(int test = 0);
		~Module();

		
		int getTest();
		
		//sf::Text getName() { return name; };
		
		virtual void update();
		virtual void render();
};

#endif
