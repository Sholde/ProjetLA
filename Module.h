#ifndef _Module_h
#define _Module_h

// Include
#include <string.h>
#include <iostream>
#include "Class.h"

// Using
using namespace std;

// Class
class Module {
	private:
		string nom;
	public:
		Module(string nom);
		~Module();
		friend ostream& operator<<(ostream& out, Module& module);
};
#endif
