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
		Vanne(const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~Vanne();
		
		bool getOpen();
		
		void update() {};
		void render(Interface *interface);
};

#endif
