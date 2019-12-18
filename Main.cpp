#include <SFML/Graphics.hpp>
#include "System.hh"

int main()
{
  System system;

  while (system.window.isOpen())
  {
    sf::Event event;
    system.update();
    while (system.window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        system.window.close();
    }
		system.render();
  }
  return 0;
}
