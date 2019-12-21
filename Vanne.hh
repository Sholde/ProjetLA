#ifndef _Vanne_hh
#define _Vanne_hh

#include "Include.hh"

class Vanne: public Module {
	// private field
	protected:
		bool isOpen;
	
	// public field
	public:
		Vanne(const char* name);
		~Vanne();
		
		void update();
		void render() {};
};

#endif
