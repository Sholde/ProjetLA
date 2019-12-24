#ifndef _Moteur_hh
#define _Moteur_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Moteur: public Module {
	// private field
	bool isFeed;
	
	// vecteur ou il y aura 2 vanne normal
	vector<VanneNormal*> vanne_normal;
	
	// réservoir qui alimente direct
	Reservoir *reservoir;
	
	Box box;
	
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
