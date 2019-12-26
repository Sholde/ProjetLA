#ifndef _VanneTransi_hh
#define _VanneTransi_hh

#include "Include.hh"

class VanneTransi: public Vanne {
	
	int flow = 10;
	Reservoir *left;
	Reservoir *right;
	
	// public field
	public:
		VanneTransi(const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~VanneTransi();
		
		void initReservoir(Reservoir *l, Reservoir *r);
		
		void share();
		void open();
		
		void update();
};

#endif
