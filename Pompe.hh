#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Pompe: public Module {
	// private field
	bool isActive;
	bool isFailure;
	bool isMain;
	
	sf::Vector2f pos_circle;
	float radius;
	Box box;
	
	// public field
	public:
		Pompe(const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~Pompe() {};
		
		bool getActive();
		void setActive(bool boolean);
		void setIsMain();
		
		void update();
		void render(Interface *interface);
};

#endif
