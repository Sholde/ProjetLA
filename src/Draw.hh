#ifndef _Draw_hh
#define _Draw_hh

#include <SFML/Graphics.hpp>
#include "Include.hh"
#include <string>
using namespace std;

void draw_rectangle(sf::RenderWindow &window, sf::Vector2f pos, sf::Vector2f size, sf::Color color);

void draw_circle(sf::RenderWindow &window, sf::Vector2f pos, float radius, sf::Color color);

void draw_text(sf::RenderWindow &window, sf::Vector2f pos, string name, sf::Font font, int size, sf::Color color);

#endif
