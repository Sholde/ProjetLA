#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "Module.hh"

class Pompe: public Module{
	// private field
	bool isActive;
	
	// public field
	public:
		Pompe(const char* name, sf::Font &font);
		~Pompe() {};
		
		void update() {};
		void render() {};
};

#endif
