#ifndef _Cercle_hh
#define _Cercle_hh

#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"

class Cercle {
	// private field
	System* system;
	sf::CircleShape shape;
	int speed = 1;
	
	// public field
	public:
		Cercle(System* system);
		~Cercle();
		
		// calcul
		void update();
		
		// affichage
		void render();
};

#endif
