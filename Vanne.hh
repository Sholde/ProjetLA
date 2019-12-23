#ifndef _Vanne_hh
#define _Vanne_hh

#include "Include.hh"

class Vanne: public Module {
	// private field
	protected:
		bool isOpen;
		sf::Vector2f pos_circle;
		float radius;
	
	// public field
	public:
		Vanne(const char* name, int = 0, int = 0);
		~Vanne();
		
		bool getOpen();
		
		void update() {};
		void render(Interface *interface);
		
		friend void draw_circle(Interface *interface, sf::Vector2f pos, float radius, sf::Color color);
};

#endif
