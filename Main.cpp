
#include <SFML/Graphics.hpp>
#include "Include.hh"

// main
int main () {
	System system;
	
	Interface interface;
	interface.initSystem(&system);
	interface.start();
	
	return 0;
}
