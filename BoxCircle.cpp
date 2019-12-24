
#include "Include.hh"

BoxCircle::BoxCircle(sf::Vector2f pos, int radius, int margin)
		:edge(radius),
		inside(radius - margin) {

	this->edge.setPosition(pos);
	this->edge.setFillColor(sf::Color::White);
	this->inside.setPosition(pos.x + margin, pos.y + margin);
	this->inside.setFillColor(sf::Color::Red);
	this->margin = margin;
}

BoxCircle::~BoxCircle() {}

void BoxCircle::setColor(sf::Color color) {
	this->inside.setFillColor(color);
}

sf::Vector2f BoxCircle::getPoint() {
	return this->edge.getPosition();
}

void BoxCircle::render(Interface *interface) {
	interface->statement.draw(edge);
	interface->statement.draw(inside);
}
