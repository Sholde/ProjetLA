#include <SFML/Graphics.hpp>
#include <string>
#include "Class.hh"
#include "Constants.hh"
#include "Interface.hh"
#include "Pompe.hh"

int main()
{
  Interface interface(WIDTH, HEIGTH, "Dashboard");

	sf::Font font;
	if (!font.loadFromFile("arial_narrow_7.ttf"))
	{
			return 1;
	}
	std::string s("p1");
	sf::Text t(s, font, 30);
	Pompe p(t);
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
