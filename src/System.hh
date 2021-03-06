#ifndef _System_hh
#define _System_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <list>
using namespace std;

class System {
	// private field
	std::list<Module*> composant;
	int x = 0;
	
	// public field
	public:
		System(Utilisateur *user);
		~System();
		
		void initVanne(Reservoir *r1, VanneTransi *v, Reservoir *r2);
		void initVanne(Reservoir *r1, Reservoir *r2, VanneNormal *v1, VanneNormal *middle, VanneNormal *v2, Moteur *m1, Moteur * m2);
		
		void createIssue();
		void handleClicStatement(int &x, int &y);
		void handleClicDashboard(int &x, int &y);
		void checkPompeMoteur();
		bool checkMoteur();
		
		void update();
		void render(Interface *interface);
};

#endif
