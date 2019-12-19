#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include <string>
#include "Class.hh"
#include "Constants.hh"
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
		Pompe(float = radius_pompe, sf::Color = sf::Color::Green);
		~Pompe();
		
		void initName(const std::string &name, sf::Font &font, const int &size);
		
		// le system appelle cette fonction quand il add ce cercle
		void initInterface(Interface* interface);
		
		// calcul
		void update();
		
		// affichage
		void render();
};

#endif
