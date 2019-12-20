#ifndef _System_hh
#define _System_hh

#include <list>
#include "Module.hh"

class System {
	// private field
	list<Module*> composant;
	
	// public field
	public:
		System();
		~System();
		
		void add(Module* module);
		
		void update();
		void render();
};

#endif
