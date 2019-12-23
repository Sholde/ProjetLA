
#include "Include.hh"
#include <string>
using namespace std;

void draw_rectangle(Interface *interface, sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
	sf::RectangleShape rect(size);
	rect.setPosition(pos);
	rect.setFillColor(color);
	interface->statement.draw(rect);
}

void draw_circle(Interface *interface, sf::Vector2f pos, float radius, sf::Color color) {
	sf::CircleShape circle(radius);
	circle.setPosition(pos);
	circle.setFillColor(color);
	interface->statement.draw(circle);
}

void draw_text(Interface *interface, sf::Vector2f pos, string name, sf::Font font, int size, sf::Color color) {
	sf::Text text(name, font, size);
	text.setPosition(pos);
	text.setFillColor(color);
	interface->statement.draw(text);
}
