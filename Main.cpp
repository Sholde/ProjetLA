
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include "Utilisateur.hh"

// main
int main () {
	Utilisateur user;
	if(user.connection()) {
		user.choose();
		if(user.getPlay()) {
			System system(&user);
			Interface interface;
			interface.initSystem(&system);
			interface.initUser(&user);
			interface.start();
		}
		else if(user.getHistory()) {
			user.printHistory();
		}
	}
	return 0;
}
