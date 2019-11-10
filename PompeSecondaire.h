#ifndef _PompeSecondaire_h
#define _PompeSecondaire_h

// Include
#include "Class.h"

// Using
using namespace std;

// Class
class PompeSecondaire : public Pompe {
	private:
		
	public:
		PompeSecondaire(bool marche = true, bool panne = false);
		~PompeSecondaire();
};
#endif
