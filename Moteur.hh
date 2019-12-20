#ifndef _Moteur_hh
#define _Moteur_hh

#include "Include.hh"

class Moteur: public Module {
	// private field
	bool isFeed;
	Reservoir *reservoir;
	
	// public field
	public:
		Moteur(const char* name);
		~Moteur() {};
		
		void update();
		void render() {};
};

#endif
