#ifndef _Vanne_h
#define _Vanne_h

// Include
#include <list>
#include "Class.h"

// Using
using namespace std;

// Class
class Vanne : public Module {
	private:
		bool estFerme;
		bool estBloque;
	public:
		Vanne(bool estFerme = true, bool estBloque = false):Module("Vanne"){};
		~Vanne() {};
		bool getEstFerme();
		void setEstFerme(bool estFerme);
		bool getEstBloque();
		void setEstBloque(bool estBloque);
};
#endif
