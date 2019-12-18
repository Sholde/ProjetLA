#ifndef _Cercle_hh
#define _Cercle_hh

#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"

class Cercle {
	// private field
	System* system;
	sf::CircleShape shape;
	
	// vitesse de céplacement
	int speed;
	
	// affichage
	int time = 0;
	int limit = 6;
	
	// public field
	public:
		Cercle(float = 100.f, sf::Color = sf::Color::Green);
		~Cercle();
		
		// le system appelle cette fonction quand il add ce cercle
		void initSystem(System* system);
		
		// calcul
		void update();
		
		// affichage
		void render();
};

#endif
