#ifndef _VanneTransition_h
#define _VanneTransition_h

// Include
#include <list>
#include "Class.h"
#include <string.h>
#include "Module.h"

// Using
using namespace std;

// Class
class VanneTransition : public Vanne {
	private:
		list<Reservoir*> reservoirs; // car pas de différenciation entre chaque réservoirs
	public:
		VanneTransition(string nom, bool est_ferme = true, bool est_bloque = false);
		~VanneTransition();
		void init(list<Reservoir*> reservoirs);
};
#endif
