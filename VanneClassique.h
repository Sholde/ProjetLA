#ifndef _VanneClassique_h
#define _VanneClassique_h

// Include
#include <list>
#include "Class.h"
#include <string.h>
#include "Module.h"

// Using
using namespace std;

// Class
class VanneClassique : public Vanne {
	private:
		list<Reservoir*> reservoirs; // car pas de différenciation entre chaque réservoirs
		list<Moteur*> moteurs; // car pas de différenciation entre chaque moteurs
	public:
		VanneClassique(string nom, bool est_ferme = true, bool est_bloque = false);
		~VanneClassique();
		void init(list<Reservoir*> reservoirs, list<Moteur*> moteurs);
};
#endif
