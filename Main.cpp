#include <SFML/Graphics.hpp>
#include "Module.hh"
#include "Pompe.hh"
#include <iostream>
#include <string>


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
	Pompe p1("P1", &font);
	
	// jai juste enlevé le cercle et jessaye d'afficher le text qui est dans la pompe
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
			sf::Event event;
			while (window.pollEvent(event))
			{
					if (event.type == sf::Event::Closed)
							window.close();
			}

			window.clear();
			window.draw(p1.getName());
			window.display();
	}
	
	return 0;
}
