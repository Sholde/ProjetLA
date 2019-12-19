#ifndef _Vanne_hh
#define _Vanne_hh

class Vanne : public Module {
	// private field
	bool isBroke;
	bool isOpen;
	
	// public field
	public:
		Vanne(const char* name);
		~Vanne();
		
		void update();
		void render();
};

#endif
