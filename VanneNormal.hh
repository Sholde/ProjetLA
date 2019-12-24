#ifndef _VanneNormal_hh
#define _VanneNormal_hh

#include "Include.hh"
#include <list>

class VanneNormal: public Vanne {
	
	Reservoir *rl;
	VanneNormal *vl;
	Moteur *ml;
	
	Reservoir *rr;
	VanneNormal *vr;
	Moteur *mr;
	
	// public field
	public:
		VanneNormal(const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~VanneNormal();
		
		void initLeft(Reservoir *r, VanneNormal *v, Moteur *m);
		void initRight(Reservoir *r, VanneNormal *v, Moteur *m);
		void open();
		void update();
		void render();
};

#endif
