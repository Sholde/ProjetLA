#ifndef _Pompe_h
#define _Pompe_h

// Include
#include <list>
#include "Class.h"

// Using
using namespace std;

// Class
class Pompe : public Module {
	private:
		bool enMarche;
		bool enPanne;
		Moteur moteur;
		Vanne vanne1;
		Vanne vanne2;
	public:
		Pompe(bool marche = true, bool panne = false);
		~Pompe();
		bool getEnMarche();
		bool getEnPanne();
};
#endif
