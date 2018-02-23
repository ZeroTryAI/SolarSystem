#include "System.h"
#include <Windows.h>
#include <iostream>

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
	
	int timestep = 1;

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

		for (auto body : bodies)
		{
			for (auto other : bodies)
			{
				if ((body->getName() == "Earth") && (body->getName() != other->getName()))
				{
					std::cout << "Old speed" << other->getVel().x << " " << other->getVel().y << std::endl;
					other->setPos(other->getPos() + other->getVel());
					float x0 = body->getPos().x;
					float y0 = body->getPos().y;

					float x1 = other->getPos().x;
					float y1 = other->getPos().y;

					float dist = sqrt((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1));
					sf::Vector2f RadVec = (other->getPos() - body->getPos()) / dist;
					sf::Vector2f FGrav = -(RadVec*12000.f) / (dist*dist);
					other->setVeloc(other->getVel() + FGrav);
					std::cout << "New speed" << other->getVel().x << " " << other->getVel().y << std::endl;
					other->setPos(other->getPos() + other->getVel());
				}
			}
		}

		window.clear();
		window.draw(stars);
		for (int i = 0; i < bodies.size(); i++)
			bodies[i]->draw(&window);

		window.display();
		Sleep(500/33);
	}
}
