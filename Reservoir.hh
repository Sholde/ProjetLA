#ifndef _Reservoir_hh
#define _Reservoir_hh

#include "Include.hh"
#include <vector>

class Reservoir: public Module {
	// private field
	bool isFull;
	
	// Pompe
	Pompe* main;
	Pompe* second;
	
	// Vanne
	
	// vecteur ou il y aura 2 vanne normal
	vector<VanneNormal*> vanne_normal;
	
	// vecteur ou il y aura 1 ou 2 vanne transi
	vector<VanneTransi*> vanne_transi;
	
	// alimente un seul moteur direct
	Moteur *moteur;
	
	// public field
	public:
		Reservoir(const char* name);
		~Reservoir();
		
		void initMoteur(Moteur *mot);
		
		void update();
		void render() {};
};

#endif
