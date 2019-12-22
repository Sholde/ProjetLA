#ifndef _Reservoir_hh
#define _Reservoir_hh

#include "Include.hh"
#include <vector>

class Reservoir: public Module {
	// private field
	bool isFull;
	
	// Pompe
	Pompe* main;
	Pompe* second;
	
	// Vanne
	
	// vecteur ou il y aura 2 vanne normal
	vector<VanneNormal*> vanne_normal;
	
	// vecteur ou il y aura 1 ou 2 vanne transi
	vector<VanneTransi*> vanne_transi;
	
	// alimente un seul moteur direct
	Moteur *moteur;
	
	sf::Vector2f pos_rect;
	sf::Vector2f size_rect;
	
	// public field
	public:
		Reservoir(const char* name, int = 0, int = 0);
		~Reservoir();
		
		void initMoteur(Moteur *mot);
		void addVanneTransi(VanneTransi* v);
		void initPompe(Pompe *m, Pompe *s);
		void addVanneNormal(VanneNormal *v);
		
		bool checkPompe();
		bool checkfeed();
		
		void update();
		void render(Interface *interface);
		
		friend void draw_rectangle(Interface *interface, sf::Vector2f pos, sf::Vector2f size, sf::Color color);
};

#endif
