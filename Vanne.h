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
		bool estOuvert;
		bool estBloque;
		Module* module1;
		Module* module2;
	public:
		Vanne(bool estOuvert = true, bool estBloque = false);
		~Vanne();
		bool getEstOuvert();
		bool getEstBloque();
};
#endif
