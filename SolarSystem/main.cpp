#include "System.h"
#include "Vector2f.h"


int main()
{
	System sys;

	Body earth("Earth", sf::Vector2f(800, 300), sf::Vector2f(0, 0), "earth.jpg", 20.f, 500.f);
	Body moon("Moons", sf::Vector2f(600, 200), sf::Vector2f(4, -1),"moon.jpg", 8.f, 200.f);

	sys.addBody(earth);
	sys.addBody(moon);

	sys.action();

	return 0;
}