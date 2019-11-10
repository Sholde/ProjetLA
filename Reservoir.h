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
		Pompe secondaire;
	public:
		Reservoir(int capacite = 0, bool plein = true);
		~Reservoir();
		int getCapacite();
		bool getEstPlein();
};
#endif
