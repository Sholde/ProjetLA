#ifndef _Reservoir_hh
#define _Reservoir_hh

#include "Include.hh"
#include <vector>

class Reservoir: public Module {
	// private field
	bool isFull;
	int capacity;
	Pompe* main;
	Pompe* second;
	vector<VanneNormal*> vanne_normal;
	vector<VanneTransi*> vanne_transi;
	Moteur *moteur;
	Box rect;
	
	// public field
	public:
		Reservoir(const char* name, int capacity, const sf::Vector2f &st);
		~Reservoir();
		
		int &getCapacity();
		void setCapacity(int &capacity);
		
		void initMoteur(Moteur *mot);
		void addVanneTransi(VanneTransi* v);
		void initPompe(Pompe *m, Pompe *s);
		void addVanneNormal(VanneNormal *v);
		
		bool checkAllPompe();
		bool checkPompe();
		bool checkFeed();
		
		bool getFull();
		void setFull(bool boolean);
		
		void handleClicStatement(int &x, int &y);
		
		void update();
		void render(Interface *interface);
};

#endif
