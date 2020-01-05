#include "Include.hh"

Box::Box(sf::Vector2f pos, int x, int y, int margin)
		:edge(sf::Vector2f(x, y)),
		inside(sf::Vector2f(x - margin * 2, y - margin * 2)) {

	this->edge.setPosition(pos);
	this->edge.setFillColor(sf::Color::White);
	this->inside.setPosition(pos.x + margin, pos.y + margin);
	this->inside.setFillColor(sf::Color::Black);
	this->margin = margin;
}

Box::~Box() {}

sf::Vector2f Box::getPoint() {
	return this->edge.getPosition();
}

sf::Vector2f Box::getSize() {
	return this->edge.getSize();
}

void Box::setColor(sf::Color color) {
	this->inside.setFillColor(color);
}

bool Box::isClicOn(int &x, int &y) {
	sf::Vector2f pos = this->edge.getPosition();
	sf::Vector2f size = this->edge.getSize();
	
	return (x >= pos.x && x <= pos.x + size.x
			&& y >= pos.y && y <= pos.y + size.y);
}

void Box::render(sf::RenderWindow &window) {
	window.draw(edge);
	window.draw(inside);
}
