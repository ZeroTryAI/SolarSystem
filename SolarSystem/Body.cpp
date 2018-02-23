#include "Body.h"

Body::Body()
	:CircleShape(),pos(0.f,0.f),radius(100.f)
{	
	name = 'body';
	mass = 0.0;
	setFillColor(sf::Color::Yellow);
	setPosition(sf::Vector2f(0.f, 0.f));
	setRadius(100.f);
}

Body::Body(std::string name_, sf::Vector2f pos_, sf::Vector2f vel_, std::string texture_, float radius_, float mass_)
	:CircleShape(), pos(pos_.x, pos_.y), radius(radius_)
{
	v = vel_;
	name = name_;
	mass = mass_;
	setPosition(pos_);
	setRadius(radius_);

	texture.loadFromFile(texture_);
	texture.setSmooth(true);

	setTexture(&texture);
}


bool Body::operator!=(Body& rhv)
{
	return (name==rhv.getName());
}

void Body::draw(sf::RenderWindow* window_)
{
	setPosition(this->getPos());
	window_->draw(*this);
}

std::string Body::getName(){ return name; }

sf::Vector2f Body::getPos(){ return pos; }

sf::Vector2f Body::getVel(){ return v; }

float Body::getMass(){ return mass; }

void Body::setPos(sf::Vector2f pos_)
{
	pos = pos_;
}

void Body::setVeloc(sf::Vector2f vel_)
{
	v = vel_;
}

void Body::setForce(sf::Vector2f force_)
{
}

