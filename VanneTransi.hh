#ifndef _VanneTransi_hh
#define _VanneTransi_hh

#include "Include.hh"

class VanneTransi: public Vanne {
	
	// rien a commenté
	Reservoir *left;
	Reservoir *right;
	
	// public field
	public:
		VanneTransi();
		~VanneTransi();
		
		void update();
		void render() {};
};

#endif
