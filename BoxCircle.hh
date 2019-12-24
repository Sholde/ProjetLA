#ifndef _BoxCircle_hh
#define _BoxCircle_hh

#include "Include.hh"

class BoxCircle {
	// private field
	sf::CircleShape edge;
	sf::CircleShape inside;
	int margin;
	
	//public field
	public:
		BoxCircle(sf::Vector2f pos, int radius, int margin);
		~BoxCircle();
		
		void setColor(sf::Color color);
		sf::Vector2f getPoint();
		
		void render(Interface *interface);
};

#endif
