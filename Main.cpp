
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include "Utilisateur.hh"

// main
int main () {
	Utilisateur user;
	if(user.connection()) {
		user.choose();
		if(user.getPlay()) {
			System system;
			Interface interface;
			interface.initSystem(&system);
			interface.start();
		}
		else if(user.getHistory()) {
			user.printHistory();
		}
	}
	return 0;
}
