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
		bool estAlimente;
		list<Module> chemin;
	public:
		Moteur(string nom, list<Module> chemin, bool estAlimente = false):Module(nom) {};
		~Moteur() {};
		bool getEstAlimente();
		void setEstAlimente(bool estAlimente);
		void calculEstAlimente();
};
#endif
