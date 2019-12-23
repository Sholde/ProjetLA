
#include <SFML/Graphics.hpp>
#include "Include.hh"

Interface::Interface(int width, int height)
		:statement(sf::VideoMode(width, height), "Statement"),
		dashboard(sf::VideoMode(width, height), "Dashboard")
		,font() {
			
	if (!this->font.loadFromFile("arial_narrow_7.ttf")) {
		exit(1);
	}
}

Interface::~Interface() {}

void Interface::initSystem(System *s) {
	this->system = s;
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
			if(event.type == sf::Event::Closed) {
				statement.close();
				dashboard.close();
			}
		}
	}
	else if(dashboard.hasFocus()) {
		while(dashboard.pollEvent(event))
		{
			if(event.type == sf::Event::Closed) {
				statement.close();
				dashboard.close();
			}
		}
	}
}
