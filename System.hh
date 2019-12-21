#ifndef _System_hh
#define _System_hh

#include "Include.hh"
#include <list>
using namespace std;

class System {
	// private field
	std::list<Module*> composant;
	
	// public field
	public:
		System();
		~System();
		
		void initVanne(Reservoir *r1, VanneTransi *v, Reservoir *r2);
		
		void update() {};
		void render();
};

#endif
