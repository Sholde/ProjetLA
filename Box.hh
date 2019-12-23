#ifndef _Box_hh
#define _Box_hh

#include "Include.hh"

class Box {
	// private field
	sf::RectangleShape edge;
	sf::RectangleShape inside;
	sf::Vector2f size;
	int margin;
	
	//public field
	public:
		Box(sf::Vector2f pos, int x, int y, int margin);
		~Box();
		
		void render(Interface *interface);
};

#endif
