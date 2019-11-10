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
		list<Module> relier;
	public:
		Pompe(bool marche = true, bool panne = false);
		~Pompe();
		bool getEnMarche();
		bool getEnPanne();
};
#endif
