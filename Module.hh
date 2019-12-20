#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

class Module {
	// private field
	protected:
		string name;
	
	// public field
	public:
		Module(const char* name);
		~Module();
		
		void update() {};
		virtual void render() {};
};

#endif
