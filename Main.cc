#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(400, 200), "Test");
  sf::CircleShape shape(100.f);
  int x = 1;
  shape.setFillColor(sf::Color::Green);
  
  int i = 0;

  while (window.isOpen())
  {
    i++;
    sf::Event event;
    if(i == 6) {
      i = 0;
      if(shape.getPosition().x > 200) {
        x = -1;
      }
      if(shape.getPosition().x < 0) {
        x = 1;
      }
      shape.setPosition(shape.getPosition().x + x, shape.getPosition().y);
    }
    while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();
      }

      window.clear();
      window.draw(shape);
      window.display();
  }
  int a = 0;
  return a;
}
