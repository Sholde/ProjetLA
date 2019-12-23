#include "Include.hh"

Vanne::Vanne(const char* name, sf::Vector2f pos)
		:Module(name, sf::Vector2f(pos.x - 15, pos.y + 40)),
		pos_circle(pos.x - 22.5, pos.y + 30) {
	this->radius = 28.f;
	this->isOpen = false;
}

Vanne::~Vanne() {}

bool Vanne::getOpen() {
	return this->isOpen;
}

void Vanne::render(Interface *interface) {
	int DECAL = 3;
	draw_circle(interface->statement, this->pos_circle, this->radius, sf::Color::White);
	sf::Vector2f tmp = sf::Vector2f(this->pos_circle.x + DECAL, this->pos_circle.y + DECAL);
	draw_circle(interface->statement, tmp, this->radius - DECAL, this->color);
	
	
	draw_text(interface->statement, this->pos_text, this->name, interface->font, 25, sf::Color::Black);
	
	draw_text(interface->dashboard, this->pos_text, this->name, interface->font, 25, sf::Color::White);
}
