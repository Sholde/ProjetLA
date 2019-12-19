#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include <string>
#include "Class.hh"
#include "Interface.hh"

class Pompe {
	// private field
	Interface* interface;
	sf::CircleShape shape;
	sf::Text name;
	
	// affichage
	int time = 0;
	int limit = 6;
	
	// public field
	public:
		Pompe(sf::Text name, float = 100.f, sf::Color = sf::Color::Green);
		~Pompe();
		
		// le system appelle cette fonction quand il add ce cercle
		void initInterface(Interface* interface);
		
		// calcul
		void update();
		
		// affichage
		void render();
};

#endif
