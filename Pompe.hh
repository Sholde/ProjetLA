#ifndef _Pompe_hh
#define _Pompe_hh

class Pompe : public Module {
	// private field
	bool isActive;
	
	// public field
	public:
		Pompe(const char* name);
		~Pompe();
		
		void update();
		void render();
};

#endif
