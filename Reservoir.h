#ifndef _Reservoir_h
#define _Reservoir_h

// Include
#include <list>
#include "Class.h"

// Using
using namespace std;

// Class
class Reservoir : public Module {
	private:
		int capacite;
		bool estPlein;
		Pompe primaire;
		Pompe secours;
	public:
		Reservoir(Pompe& p, Pompe& secours, int capacite = 0, bool plein = false):Module("Réservoir"){};
		~Reservoir() {};
		int getCapacite();
		void setCapacite(int capacite);
		bool getEstPlein();
		void setEstPlein(bool plein);
};
#endif
