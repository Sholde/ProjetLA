#ifndef _Moteur_hh
#define _Moteur_hh

class Moteur : public Module {
	// private field
	bool isFeed;
	
	// public field
	public:
		Moteur(const char* name);
		~Moteur() {};
		
		void update();
		void render();
};

#endif
