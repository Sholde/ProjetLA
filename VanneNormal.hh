#ifndef _VanneNormal_hh
#define _VanneNormal_hh

#include "Include.hh"
#include <list>

class VanneNormal: public Vanne {
	
	// tous les modules qui arrive de gauche
	std::list<Module*> left;
	
	// tous les modules qui arrive de droite
	std::list<Module*> right;
	
	// il y aura juste a callculer si le carburant n'arrive pas des deux coté
	
	// public field
	public:
		VanneNormal();
		~VanneNormal();
		
		void update();
		void render() {};
};

#endif
