#ifndef _Moteur_hh
#define _Moteur_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Moteur: public Module {
	// private field
	bool isFeed;
	VanneNormal* v1;
	VanneNormal* v2;
	Reservoir *reservoir;
	Box rect;
	Pompe *pompe;
	
	// public field
	public:
		Moteur(Utilisateur *user, const char* name, const sf::Vector2f &st);
		~Moteur();
		
		void initReservoir(Reservoir *res);
		void addVanneNormal(VanneNormal *v);
		
		bool isTaken();
		void clear();
		void setPompe(Pompe* p);
		bool cF();
		void checkFeed();
		bool getFeed();
		
		void update();
		void render(Interface *interface);
};

#endif
