#ifndef _Pompe_h
#define _Pompe_h

// Include
#include <string.h>
#include "Class.h"
#include "Module.h"

// Using
using namespace std;

// Class
class Pompe : public Module {
	private:
		bool en_marche;
		bool en_panne;
	public:
		Pompe(string nom, bool marche = true, bool panne = false);
		~Pompe();
};
#endif
