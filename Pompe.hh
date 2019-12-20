#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "Module.hh"

class Pompe{
	// private field
	bool isActive;
	
	// public field
	public:
		Pompe();
		~Pompe() {};
		
		void update() {};
		void render() {};
};

#endif
