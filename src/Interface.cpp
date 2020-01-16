#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <iostream>
using namespace std;

Interface::Interface(int width, int height)
		:	font()
		, statement(sf::VideoMode(width, height), "Statement")
		, dashboard(sf::VideoMode(500, 400), "Dashboard") {
			
	if (!this->font.loadFromFile("ressources/arial_narrow_7.ttf")) {
		exit(1);
	}
}

Interface::~Interface() {}

void Interface::initSystem(System *s) {
	this->system = s;
}

void Interface::initUser(Utilisateur *u) {
	this->user = u;
}

void Interface::start() {
	while(statement.isOpen() && dashboard.isOpen())
	{
		time++;
		if(time >= fps) {
			time = 0;
			sf::Event event;
			// update
			system->update();
			
			// handle event
			this->handleEvent(event);

			// render
			this->render();
		}
	}
}

void Interface::render() {
	statement.clear();
	dashboard.clear();
	system->render(this);
	statement.display();
	dashboard.display();
}

void Interface::handleEvent(sf::Event &event) {
	if(statement.hasFocus()) {
		while(statement.pollEvent(event))
		{
			this->closeEvent(event);
			this->clicEvent(event);
		}
	}
	else if(dashboard.hasFocus()) {
		while(dashboard.pollEvent(event))
		{
			this->closeEvent(event);
			this->clicEvent(event);
		}
	}
}

void Interface::closeEvent(sf::Event &event) {
	if(event.type == sf::Event::Closed) {
		statement.close();
		dashboard.close();
		this->printHistory();
	}
}

void Interface::printHistory() {
	if(!this->system->checkMoteur()) {
		this->user->zero();
	}
	this->user->checkRating();
	this->user->addDate();
	this->user->printJson();
}

void Interface::clicEvent(sf::Event &event) {
	if(event.type == sf::Event::MouseButtonPressed) {
		int x = event.mouseButton.x;
		int y = event.mouseButton.y;
		if(dashboard.hasFocus()) {
			this->system->handleClicDashboard(x, y);
		}
		if(statement.hasFocus()) {
			this->system->handleClicStatement(x, y);
		}
	}
}
