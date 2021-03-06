#ifndef _Pompe_hh
#define _Pompe_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"

class Pompe: public Module {
	// private field
	bool isActive;
	bool isFailure;
	bool isMain;
	Moteur* mot;
	BoxCircle circle;
	Box button;
	sf::Vector2f pos_db;
	
	// public field
	public:
		Pompe(Utilisateur *user, const char* name, const sf::Vector2f &st);
		Pompe(Utilisateur *user, const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~Pompe() {};
		
		bool getActive();
		bool getIsMain();
		void setActive();
		void setIsMain();
		
		bool isTaken();
		void take(Moteur* mot);
		void clear();
		bool calculCarburant(Moteur* mot);
		
		bool checkFeed();
		void handleClicDashboard(int &x, int &y);
		void handleClicStatement(int &x,int &y);
		bool isClickOn(int &x,int &y);
		
		void update();
		void render(Interface *interface);
};

#endif
