#ifndef _Reservoir_hh
#define _Reservoir_hh

#include "Include.hh"
#include <vector>

class Reservoir: public Module {
	// private field
	bool isFull;
	Pompe* main;
	Pompe* second;
	vector<VanneNormal*> vanne_normal;
	vector<VanneTransi*> vanne_transi;
	Moteur *moteur;
	Box rect;
	Box button;
	
	// public field
	public:
		Reservoir(const char* name, const sf::Vector2f &st, const sf::Vector2f &db);
		~Reservoir();
		
		void initMoteur(Moteur *mot);
		void addVanneTransi(VanneTransi* v);
		void initPompe(Pompe *m, Pompe *s);
		void addVanneNormal(VanneNormal *v);
		
		bool checkPompe();
		bool checkfeed();
		
		void setFull(bool boolean);
		
		void handleClic(int &x, int &y);
		
		void update();
		void render(Interface *interface);
};

#endif
