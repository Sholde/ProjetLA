#include <SFML/Graphics.hpp>
#include "Class.hh"
#include "System.hh"
#include "Cercle.hh"

int main()
{
  System system;
  Cercle c1(100.f, sf::Color::Red);
	system.add(&c1);

  while (system.window.isOpen())
  {
    sf::Event event;
    system.update();
    system.handleEvent(event);
		system.render();
  }
  return 0;
}
