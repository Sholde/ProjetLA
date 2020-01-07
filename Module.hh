#ifndef _Module_hh
#define _Module_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

class Module {
	// private field
	protected:
		string name;
		sf::Vector2f pos_st;
		Utilisateur *user;
		sf::Vertex line[2];
	
	// public field
	public:
		Module(Utilisateur* user, const char* name, const sf::Vector2f &st);
		~Module();
		
		sf::Vector2f &getPos();
		void setLine(sf::Vector2f v1, sf::Vector2f v2, sf::Color color);
		
		virtual void handleClicStatement(int &x, int &y) {};
		virtual void handleClicDashboard(int &x, int &y) {};
		virtual void update() {};
		virtual void render(Interface *interface) {};
		virtual bool getFeed();
		virtual void clear() {};
};

#endif
