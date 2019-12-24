#ifndef _Moteur_hh
#define _Moteur_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Moteur: public Module {
	// private field
	bool isFeed;
	vector<VanneNormal*> vanne_normal;
	Reservoir *reservoir;
	Box rect;
	
	// public field
	public:
		Moteur(const char* name, const sf::Vector2f &st);
		~Moteur();
		
		void initReservoir(Reservoir *res);
		void addVanneNormal(VanneNormal *v);
		
		void setFeed(bool boolean);
		
		void update();
		void render(Interface *interface);
};

#endif
