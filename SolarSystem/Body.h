#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <math.h>

#define G 6.67428e-11 //The gravitational constant
#define AU (149.6e6 * 1000) //Astro units
#define SCALE 250 / AU 

class Body: public sf::CircleShape
{
public:
	Body();
	Body(std::string name, sf::Vector2f pos_, std::string texture_, double radius_, double mass_, sf::Vector2f vel_);
	
	sf::Vector2f calcAttraction(Body* othBody);
	
	bool operator!=(Body& rhv);
	void draw(sf::RenderWindow* window_);
	
	std::string getName();
	sf::Vector2f getPos();
	sf::Vector2f getVel();
	double getMass();
	
	void setPos(sf::Vector2f pos_);
	void setVeloc(sf::Vector2f vel_);
	void setForce(sf::Vector2f force_);
private:
	// Name of body
	std::string name;
	// Position in Decade system
	sf::Vector2f pos;
	// Radius of object
	double radius;
	// Texture of shape
	sf::Texture texture;
	
	
	//Current force vector
	sf::Vector2f currectForce;
	// Begining velocity
	double v0;
	// Current velocity
	sf::Vector2f v;
	// Mass of body
	double mass;
};