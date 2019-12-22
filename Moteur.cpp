#include "Include.hh"
#include <iostream>
using namespace std;

Moteur::Moteur(const char* name, int x, int y):Module(name, x, y) {
	this->isFeed = false;
}

Moteur::~Moteur() {
	
}

void Moteur::initReservoir(Reservoir *res) {
	this->reservoir = res;
}

void Moteur::addVanneNormal(VanneNormal *v) {
	this->vanne_normal.push_back(v);
}

void Moteur::update() {
	if(this->reservoir->checkfeed())
		this->isFeed = true;
	else
		this->isFeed = false;
}


void Moteur::render(Interface *interface) {
	sf::RectangleShape rect(sf::Vector2f(45.f, 100.f));
	rect.setPosition(sf::Vector2f(this->point.getX() - 5, this->point.getY() - 30));
	if(this->isFeed)
		rect.setFillColor(sf::Color::Green);
	else
		rect.setFillColor(sf::Color::Red);
	interface->window.draw(rect);
	
	sf::Text text(this->name, interface->font, 30);
	text.setPosition(this->point.getX(), this->point.getY());
	interface->window.draw(text);
}
