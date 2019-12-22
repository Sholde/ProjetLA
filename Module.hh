#ifndef _Module_hh
#define _Module_hh

#include "Include.hh"
#include <string>
using namespace std;

class Module {
	// private field
	protected:
		string name;
		Point point;
	
	// public field
	public:
		Module(const char* name, int = 0, int = 0);
		~Module();
		
		string &getName();
		
		virtual void update() {};
		virtual void render(Interface *interface) {};
};

#endif
