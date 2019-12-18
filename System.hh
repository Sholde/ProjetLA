#ifndef _System_hh
#define _System_hh

#include <SFML/Graphics.hpp>
#include <list>
#include "Cercle.hh"

class System {
	// private field
	std::list<Cercle> composant;
	
	// public field
	public:
		// variable
		sf::RenderWindow window;
		
		// function
		System();
		~System();
		
		// calcul
		void update();
		
		// affichage
		void render();
};

#endif
