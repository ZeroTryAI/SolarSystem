#include "Planet.h"

Planet::Planet()
	:CircleShape(),pos(0.f,0.f),radius(100.f)
{
	setFillColor(sf::Color::Yellow);
	setPosition(sf::Vector2f(0.f, 0.f));
	setRadius(100.f);
}

Planet::Planet(sf::Vector2f pos_, std::string texture_, float radius_) 
	:CircleShape(),pos(pos_),radius(radius_)
{
	setPosition(pos_);
	setRadius(radius_);

	texture.loadFromFile(texture_);
	texture.setSmooth(true);

	setTexture(&texture);
}
