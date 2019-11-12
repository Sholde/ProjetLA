#ifndef _Reservoir_h
#define _Reservoir_h

// Include
#include <list>
#include "Class.h"
#include <string.h>
#include "Module.h"

// Using
using namespace std;

// Class
class Reservoir : public Module {
	private:
		int capacite;
		bool est_plein;
		
		Pompe* primaire; // différentiation entre pompe primaire et secondaire
		Pompe* secours; // différentiation entre pompe primaire et secondaire
		
		list<VanneClassique*> vannes_classique; // car pas de différenciation entre chaque vanne classique
		list<VanneTransition*> vannes_transition; // car pas de différenciation entre chaque vanne transition
		
		Moteur* moteur; // accès direct aux moteur
	public:
		Reservoir(string nom, int capacite = 0, bool plein = false);
		~Reservoir();
		void init(Pompe* primaire, Pompe* secours, list<VanneClassique*> vannes_classique, list<VanneTransition*> vannes_transition, Moteur* moteur);
};
#endif
