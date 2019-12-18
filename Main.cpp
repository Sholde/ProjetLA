#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"

int main()
{
  System system;
  Cercle c1(100.f, sf::Color::Red);
	system.add(&c1);
	Cercle c3(70.f, sf::Color::Blue);
	system.add(&c3);
	Cercle c2(50.f, sf::Color::Green);
	system.add(&c2);

  while (system.window.isOpen())
  {
    sf::Event event;
    system.update();
    system.handleEvent(event);
		system.render();
  }
  return 0;
}
