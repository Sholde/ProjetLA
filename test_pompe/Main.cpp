#include <SFML/Graphics.hpp>
#include <string>
#include "Class.hh"
#include "Constants.hh"
#include "Interface.hh"
#include "Pompe.hh"

int main()
{
  Interface interface(WIDTH, HEIGTH, "Dashboard");
	
	Pompe p;
	p.initName("P1", interface.font, 30);
  interface.add(&p);

	while (interface.window.isOpen())
	{
		sf::Event event; 
		interface.update();
		interface.handleEvent(event);
		interface.render();
	}
	interface.close();
	
  return 0;
}
