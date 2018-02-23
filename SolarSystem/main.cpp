#include "System.h"
#include "Vector2f.h"


int main()
{
	System sys;

	// initialize objects

	Body sun("Sun", sf::Vector2f(0 * AU, 0 * AU), "sun.png", 30.f, 1.98892e30, sf::Vector2f(0,0));
	Body earth("Earth", sf::Vector2f(1 * AU, 1*AU),"earth.jpg", 5.f, 5.9742e24, sf::Vector2f(0 , -29.783 * 1000));
	//Body moon("Moon", sf::Vector2f(0.723 * AU, 0), "moon.jpg", 8.f, 4.8685e24);

	sys.addBody(sun);
	sys.addBody(earth);
	//sys.addBody(moon);

	sys.action();

	return 0;
}