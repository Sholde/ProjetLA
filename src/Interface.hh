#ifndef _Interface_hh
#define _Interface_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Interface {
	
	// private field
	sf::Font font;
	System* system;
	Utilisateur* user;
	int time = 60;
	int fps = 60;
	sf::RenderWindow statement;
	sf::RenderWindow dashboard;
	
	// public field
	public:
		Interface(int = WIDTH, int = HEIGHT);
		~Interface();
		
		void initSystem(System *s);
		void initUser(Utilisateur *u);
		
		void start();
		void render();
		void handleEvent(sf::Event &);
		void clicEvent(sf::Event &);
		void closeEvent(sf::Event &);
		void printHistory();
		
		friend class Moteur;
		friend class Reservoir;
		friend class Pompe;
		friend class Vanne;
		friend class Box;
		friend class BoxCircle;
};

#endif
