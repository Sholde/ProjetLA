#ifndef _Pompe_h
#define _Pompe_h

// Include
#include "Class.h"

// Using
using namespace std;

// Class
class Pompe : public Module {
	private:
		bool enMarche;
		bool enPanne;
	public:
		Pompe(bool marche = true, bool panne = false):Module("Pompe"){};
		~Pompe() {};
		bool getEnMarche();
		bool getEnPanne();
		void setEnMarche(bool marche);
		void setEnPanne(bool panne);
};
#endif
