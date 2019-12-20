#ifndef _Reservoir_hh
#define _Reservoir_hh

#include "Include.hh"

class Reservoir: public Module {
	// private field
	bool isFull;
	Pompe main;
	Pompe second;
	Moteur *moteur;
	
	// public field
	public:
		Reservoir(const char* name, Pompe &main, Pompe &second);
		~Reservoir();
		
		void update();
		void render() {};
};

#endif
