#ifndef _VanneTransi_hh
#define _VanneTransi_hh

#include "Include.hh"

class VanneTransi: public Vanne {
	
	// rien a commenté
	Reservoir *left;
	Reservoir *right;
	
	// public field
	public:
		VanneTransi(const char* name);
		~VanneTransi();
		
		void initReservoir(Reservoir *l, Reservoir *r);
		
		void update();
		void render() {};
};

#endif
