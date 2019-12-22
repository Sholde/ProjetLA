#ifndef _VanneTransi_hh
#define _VanneTransi_hh

#include "Include.hh"

class VanneTransi: public Vanne {
	
	// rien a commenté
	Reservoir *left;
	Reservoir *right;
	
	// public field
	public:
		VanneTransi(const char* name, int = 0, int = 0);
		~VanneTransi();
		
		void initReservoir(Reservoir *l, Reservoir *r);
		
		Reservoir *getLeft();
		Reservoir *getRight();
		
		void update() {};
		void render();
};

#endif
