#ifndef _PompePrimaire_h
#define _PompePrimaire_h

// Include
#include "Class.h"

// Using
using namespace std;

// Class
class PompePrimaire : public Pompe {
	private:
		
	public:
		PompePrimaire(bool marche = true, bool panne = false);
		~PompePrimaire();
};
#endif
