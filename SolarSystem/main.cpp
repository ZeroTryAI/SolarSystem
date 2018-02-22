#include "Planet.h"
#include "Vector2f.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Solar System", sf::Style::Close);

	// set background
	sf::Texture background;
	sf::Sprite stars;
	background.loadFromFile("stars.jpg");
	stars.setTexture(background);

	// initialize objects
	Planet earth(sf::Vector2f(200,100),"earth.jpg",60.f);
	Planet moon(sf::Vector2f(400,400), "moon.jpg", 25.f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(stars);

		window.draw(earth);
		window.draw(moon);

		window.display();
	}

	return 0;
}