#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <math.h>

#define G 6.67428e-11 //The gravitational constant


class Body: public sf::CircleShape
{
public:
	Body();
	Body(std::string name, sf::Vector2f pos_, sf::Vector2f vel_, std::string texture_, float radius_, float mass_);
	
	bool operator!=(Body& rhv);
	void draw(sf::RenderWindow* window_);
	
	std::string getName();
	sf::Vector2f getPos();
	sf::Vector2f getVel();
	float getMass();
	
	void setPos(sf::Vector2f pos_);
	void setVeloc(sf::Vector2f vel_);
	void setForce(sf::Vector2f force_);
private:
	// Name of body
	std::string name;
	// Position in Decade system
	sf::Vector2f pos;
	// Radius of object
	float radius;
	// Texture of shape
	sf::Texture texture;
	
	// Current velocity
	sf::Vector2f v;
	// Mass of body
	float mass;
};