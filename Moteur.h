#ifndef _Moteur_h
#define _Moteur_h

// Include
#include <list>
#include "Class.h"

// Using
using namespace std;

// Class
class Moteur : public Module {
	private:
		bool estAlimente;
	public:
		Moteur(bool estAlimente = true);
		~Moteur();
		bool getEstAlimente();
};
#endif
