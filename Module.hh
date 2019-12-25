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
		sf::Vector2f pos_st;
	
	// public field
	public:
		Module(const char* name, const sf::Vector2f &st);
		~Module();
		
		virtual void handleClic(int &x, int &y) {};
		virtual void update() {};
		virtual void render(Interface *interface) {};
};

#endif
