#include "Include.hh"

Vanne::Vanne(const char* name, const sf::Vector2f &st, const sf::Vector2f &db)
		:Module(name, sf::Vector2f(st.x - 15, st.y + 40), db),
		pos_circle(st.x - 22.5, st.y + 30),
		box(sf::Vector2f(db.x - 30, db.y), 100, 40, 5) {
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
	
	
	draw_text(interface->statement, this->pos_st, this->name, interface->font, 25, sf::Color::Black);
	
	this->box.render(interface);
	draw_text(interface->dashboard, this->pos_db, this->name, interface->font, 25, sf::Color::White);
}
