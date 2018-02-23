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

Body::Body(std::string name_, sf::Vector2f pos_, std::string texture_, double radius_, double mass_, sf::Vector2f vel_)
	:CircleShape(), pos(pos_.x*SCALE, pos_.y*SCALE), radius(radius_)
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

sf::Vector2f Body::calcAttraction(Body* othBody)
{
	//calc distance
	double dx = pos.x - othBody->getPos().x, dy= pos.y - othBody->getPos().y;
	double distance = std::sqrt(dx * dx + dy * dy);
	//calc force
	double force = G * this->mass * othBody->getMass() / (distance*distance);
	//calc and return vector of force	
	double alpha = std::atan2f(dy,dx);	
	return sf::Vector2f(std::cos(alpha)*force, std::sin(alpha)*force);
}

bool Body::operator!=(Body& rhv)
{
	return (name==rhv.getName());
}

void Body::draw(sf::RenderWindow* window_)
{
	window_->draw(*this);
}

std::string Body::getName(){ return name; }

sf::Vector2f Body::getPos(){ return pos; }

sf::Vector2f Body::getVel(){ return v; }

double Body::getMass(){ return mass; }

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

