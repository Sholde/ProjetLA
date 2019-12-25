#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Pompe: public Module {
	// private field
	bool isActive;
	bool isFailure;
	bool isMain;
	BoxCircle circle;
	Box button;
	sf::Vector2f pos_db;
	
	// public field
	public:
		Pompe(const char* name, const sf::Vector2f &st);
		Pompe(const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~Pompe() {};
		
		bool getActive();
		bool getIsMain();
		void setActive();
		void setIsMain();
		
		void checkFeed();
		void handleClic(int &x, int &y);
		
		void update();
		void render(Interface *interface);
};

#endif
