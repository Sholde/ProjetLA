#ifndef _Moteur_hh
#define _Moteur_hh

#include "Include.hh"

class Moteur: public Module {
	// private field
	bool isFeed;
	
	// vecteur ou il y aura 2 vanne normal
	vector<VanneNormal*> vanne_normal;
	
	// réservoir qui alimente direct
	Reservoir *reservoir;
	
	sf::Vector2f pos_rect;
	sf::Vector2f size_rect;
	
	// public field
	public:
		Moteur(const char* name, int = 0, int = 0);
		~Moteur();
		
		void initReservoir(Reservoir *res);
		void addVanneNormal(VanneNormal *v);
		
		void setFeed(bool boolean);
		
		void update();
		void render(Interface *interface);
		
		friend void draw_rectangle(Interface *interface, sf::Vector2f pos, sf::Vector2f size, sf::Color color);
		friend void draw_text(Interface *interface, sf::Vector2f pos, string name, sf::Font font, int size, sf::Color color);
};

#endif
