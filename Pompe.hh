#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Pompe: public Module {
	// private field
	bool isActive;
	bool isFailure;
	
	// public field
	public:
		Pompe(const char* name);
		~Pompe() {};
		
		bool getActive();
		void setActive(bool boolean);
		
		void update() {};
		void render();
};

#endif
