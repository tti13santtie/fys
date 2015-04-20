#include <SFML/Graphics.hpp>
#include "world.h"
#include "object.h"
int main()
{
	using namespace fys;
	world world;
	ball * b = new ball(20);
	b->setPosition(sf::Vector2f(2,2));
	world.addObject(new rectangle(sf::Vector2f(50, 50)));
	world.addObject(new ball(50));
	//world.addObject(b);
	
	while (world.update())
		;
	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	*/

	return 0;
}