#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include "Module.hh"

class Pompe : public Module {
	// private field
	bool isActive;
	
	// public field
	public:
		Pompe(int test);
		~Pompe() {};
		
		void update() {};
		void render() {};
};

#endif
