#ifndef _Moteur_hh
#define _Moteur_hh

#include "Include.hh"

class Moteur: public Module {
	// private field
	bool isFeed;
	
	// vecteur ou il y aura 2 vanne normal
	vector<VanneNormal*> vanne_normal;
	
	// réservoir qui alimente direct
	Reservoir *reservoir;
	
	// public field
	public:
		Moteur(const char* name);
		~Moteur();
		
		void initReservoir(Reservoir *res);
		Reservoir *getReservoir();
		
		void update();
		void render() {};
};

#endif
