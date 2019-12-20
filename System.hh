#ifndef _System_hh
#define _System_hh

#include <list>
#include "Module.hh"

class System {
	// private field
	std::list<Module*> composant;
	
	// public field
	public:
		System();
		~System();
		
		void update() {};
		void render();
};

#endif
