
#include <SFML/Graphics.hpp>
#include "Include.hh"

// main
int main () {
	Utilisateur user;
	if(user.connection()) {
		System system;
		Interface interface;
		interface.initSystem(&system);
		interface.start();
	}
	
	return 0;
}
