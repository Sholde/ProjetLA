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
	Pompe p1("p1", font);
	
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
			window.draw(p1.getText());
			window.display();
	}
	
	return 0;
}
