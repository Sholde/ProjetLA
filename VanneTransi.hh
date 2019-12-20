#ifndef _VanneTransi_hh
#define _VanneTransi_hh

#include "Include.hh"

class VanneTransi: public Vanne {
	
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
