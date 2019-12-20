#ifndef _VanneNormal_hh
#define _VanneNormal_hh

#include "Include.hh"
#include <list>

class VanneNormal: public Vanne {
	
	std::list<Module*> left;
	std::list<Module*> right;
	
	// public field
	public:
		VanneNormal();
		~VanneNormal();
		
		void update();
		void render() {};
};

#endif
