#ifndef _Moteur_h
#define _Moteur_h

// Include
#include <list>
#include <string.h>
#include "Module.h"

// Using
using namespace std;

// Class
class Moteur : public Module {
	private:
		bool est_alimente;
		list<VanneClassique*> vannes_classique;
		Reservoir* reservoir;
	public:
		Moteur(string nom, bool est_alimente = false);
		~Moteur();
		void init(list<VanneClassique*> vannes_classique, Reservoir* reservoir);
};
#endif
