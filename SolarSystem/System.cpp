#include "System.h"



System::System()
{
}


System::~System()
{
}

void System::addBody(Body& body_)
{
	bodies.push_back(&body_);
}

void System::action()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Solar System", sf::Style::Close);
	int timestep = 24 * 3600;
	// set background
	sf::Texture background;
	sf::Sprite stars;
	background.loadFromFile("stars.jpg");
	stars.setTexture(background);
	
	int step = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		step++;

		std::vector<sf::Vector2f> forces;

		for (auto body : bodies)
		{
			sf::Vector2f total_force(0,0);
			for (auto other : bodies)
			{
				if (body != other)
				{
					total_force += body->calcAttraction(other);
				}
			}
			std::cout << total_force.x << ' ' << total_force.y << std::endl;
			forces.push_back(total_force);
		}

		for (int i=0;i<bodies.size();i++)
		{
			bodies[i]->setVeloc(sf::Vector2f(bodies[i]->getVel().x + forces[i].x/bodies[i]->getMass()*timestep, bodies[i]->getVel().y + forces[i].y/bodies[i]->getMass()*timestep));
			bodies[i]->setPos(sf::Vector2f(bodies[i]->getVel().x*timestep, bodies[i]->getVel().y*timestep));
			bodies[i]->sf::CircleShape::setPosition(bodies[i]->getPos().x * SCALE, bodies[i]->getPos().x * SCALE);
		}

		window.clear();
		window.draw(stars);
		for (int i = 0; i < bodies.size(); i++)
			bodies[i]->draw(&window);

		window.display();
	}
}
