#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "Constants.hh"
#include "System.hh"
#include "Cercle.hh"

int main()
{
  System system;
  Cercle c1(100.f, sf::Color::Red, 1);
	system.add(&c1);
	Cercle c3(70.f, sf::Color::Blue, 3);
	system.add(&c3);
	Cercle c2(50.f, sf::Color::Green, 2);
	system.add(&c2);
	sf::Vector2<int> vect = system.window.getPosition();
	vect.x -= WIDTH;
	system.window.setPosition(vect);
	
	System system2;
  Cercle c4(100.f, sf::Color::Red, 1);
	system2.add(&c4);

	while (system.window.isOpen() || system2.window.isOpen())
	{
		sf::Event event;
		system.update();
		system2.update();
		system.handleEvent(event);
		system2.handleEvent(event);
		system.render();
		system2.render();
	}
	system.close();
	system2.close();
	
  return 0;
}
