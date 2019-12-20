#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Class.hh"
#include "Module.hh"
#include "Pompe.hh"


// init la font car on doit la recup dans un fichier
// car sinon ca ne l'affiche pas dans la fenetre
void initFont(sf::Font &font) {
	if (!font.loadFromFile("arial_narrow_7.ttf"))
	{
			exit(1);
	}
}

// main
int main () {
	sf::Font font;
	initFont(font);
	Pompe p1(1);
	
	std::cout << p1.getTest() << std::endl;
	
	return 0;
}
