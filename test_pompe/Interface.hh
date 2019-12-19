#ifndef _Interface_hh
#define _Interface_hh

#include <SFML/Graphics.hpp>
#include <list>
#include "Class.hh"
#include "Constants.hh"
#include "Pompe.hh"

class Interface {
	// private field
	std::list<Pompe*> composant;
	
	// public field
	public:
		// variable
		sf::RenderWindow window;
		sf::Font font;
		
		// function
		Interface(int = WIDTH, int = HEIGTH, const char* = "Interface");
		~Interface();
		
		// ajoute un cercle a la liste
		void add(Pompe* p);
		
		// gere les evenememnt, ici juste la fermetuer de la fenetre
		void handleEvent(sf::Event event);
		
		// calcul
		void update();
		
		// affichage
		void render();
		
		// verifie si la fenetre est ferme et la ferme
		void close();
};

#endif
