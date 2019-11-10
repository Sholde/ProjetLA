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
	public:
		Vanne(bool estOuvert = true);
		~Vanne();
		bool getEstOuvert();
};
#endif
