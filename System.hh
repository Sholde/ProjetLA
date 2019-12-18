#ifndef _System_hh
#define _System_hh

#include <SFML/Graphics.hpp>
#include <list>
#include "Class.hh"
#include "Constants.hh"
#include "Cercle.hh"

class System {
	// private field
	std::list<Cercle*> composant;
	
	// public field
	public:
		// variable
		sf::RenderWindow window;
		
		// function
		System(int = WIDTH, int = HEIGTH);
		~System();
		
		// ajoute un cercle a la liste
		void add(Cercle* c);
		
		// gere les evenememnt, ici juste la fermetuer de la fenetre
		void handleEvent(sf::Event event);
		
		// calcul
		void update();
		
		// affichage
		void render();
};

#endif
