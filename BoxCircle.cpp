
#include "Include.hh"
#include <iostream>
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

bool BoxCircle::isClicOn(int &x, int &y) {
	sf::Vector2f pos = this->edge.getPosition();
	int radius = this->edge.getRadius();
	if(pos.x + 2 * radius > x
		&& pos.x < x 
		&& pos.y + 2 * radius > y 
		&& pos.y < y) {
				return true;
	}
	return false;
}
