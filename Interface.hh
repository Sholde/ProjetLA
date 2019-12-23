#ifndef _Interface_hh
#define _Interface_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Interface {
	
	// private field
	sf::Font font;
	System* system;
	int time = 60;
	int fps = 60;
	sf::RenderWindow statement;
	sf::RenderWindow dashboard;
	
	// public field
	public:
		Interface(int = WIDTH, int = HEIGHT);
		~Interface();
		
		void initSystem(System *s);
		
		void start();
		void render();
		void handleEvent(sf::Event &);
		
		friend void draw_rectangle(Interface *interface, sf::Vector2f pos, sf::Vector2f size, sf::Color color);
		friend void draw_circle(Interface *interface, sf::Vector2f pos, float radius, sf::Color color);
		friend void draw_text(Interface *interface, sf::Vector2f pos, string name, sf::Font font, int size, sf::Color color);
		
		friend class Moteur;
		friend class Reservoir;
		friend class Pompe;
		friend class Vanne;
};

#endif
