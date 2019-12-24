#ifndef _Box_hh
#define _Box_hh

#include "Include.hh"

class Box {
	// private field
	sf::RectangleShape edge;
	sf::RectangleShape inside;
	int margin;
	
	//public field
	public:
		Box(sf::Vector2f pos, int x, int y, int margin);
		~Box();
		
		sf::Vector2f getPoint();
		sf::Vector2f getSize();
		void setColor(sf::Color color);
		
		void render(sf::RenderWindow &window);
};

#endif
