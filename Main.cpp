
#include <SFML/Graphics.hpp>
#include "Include.hh"

// main
int main () {
	System system;
	
	Interface statement("Statement");
	statement.initSystem(&system);
	statement.start();
	
	return 0;
}
