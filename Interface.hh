#ifndef _Interface_hh
#define _Interface_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Interface {
	
	// private field
	int width;
	int height;
	sf::Font font;
	System* system;
	
	protected:
		sf::RenderWindow window;
	
	// public field
	public:
		Interface(const char* name, int = WIDTH, int = HEIGHT);
		~Interface();
		
		void initSystem(System *s);
		
		void start();
		
		friend class Moteur;
		friend class Reservoir;
};

#endif
