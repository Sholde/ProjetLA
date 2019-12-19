#ifndef _Reservoir_hh
#define _Reservoir_hh

class Reservoir : public Module {
	// private field
	bool isFull;
	Pompe main;
	Pompe second;
	
	// public field
	public:
		Reservoir(const char* name, Pompe &main, Pompe &second);
		~Reservoir();
		
		void update();
		void render();
};

#endif
