#pragma once
#include <SFML\Graphics.hpp>
#include "Planet.h"
#include <string>

class Planet: public sf::CircleShape
{
public:
	Planet();
	Planet(sf::Vector2f pos_, std::string texture_, float radius_);
	
private:
	// Position in Decade system
	sf::Vector2f pos;
	// Radius of object
	float radius;
	// Texture of shape
	sf::Texture texture;
	// Begining velocity
	float v0;
	// Current velocity
	float v;

};