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
		VanneNormal(const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~VanneNormal();
		
		void initLeft(Reservoir *r, VanneNormal *v, Moteur *m);
		void initRight(Reservoir *r, VanneNormal *v, Moteur *m);
		void open();
		void update() {};
		void render();
};

#endif
