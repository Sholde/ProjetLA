
#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

void draw_rectangle(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
	sf::RectangleShape rect(size);
	rect.setPosition(pos);
	rect.setFillColor(color);
	window.draw(rect);
}

void draw_circle(sf::RenderWindow &window, sf::Vector2f pos, float radius, sf::Color color) {
	sf::CircleShape circle(radius);
	circle.setPosition(pos);
	circle.setFillColor(color);
	window.draw(circle);
}

void draw_text(sf::RenderWindow &window, sf::Vector2f pos, string name, sf::Font font, int size, sf::Color color) {
	sf::Text text(name, font, size);
	text.setPosition(pos);
	text.setFillColor(color);
	window.draw(text);
}
