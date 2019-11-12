#ifndef _Vanne_h
#define _Vanne_h

// Include
#include <list>
#include "Class.h"
#include <string.h>
#include "Module.h"

// Using
using namespace std;

// Class
class Vanne : public Module {
	private:
		bool est_ferme;
		bool est_bloque;
	public:
		Vanne(string nom, bool est_ferme = true, bool est_bloque = false);
		~Vanne();
};
#endif
