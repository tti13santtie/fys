#include <SFML/Graphics.hpp>
#include "world.h"
#include "object.h"

int main()
{
	
	using namespace fys;
	sf::RenderWindow * wnd = new sf::RenderWindow(sf::VideoMode(1000,800), "Fysiikkaa");
	bool done = false;
	world world(wnd);
	ball * b = new ball(50);
	rectangle * r = new rectangle(sf::Vector2f(100,25));
	r->setGravity(false);
	r->setPosition(sf::Vector2f(200,775));
	b->setPosition(sf::Vector2f(200,0));
	world.addObject(r);
	world.addObject(b);
	
	sf::Clock clock;
	sf::Time elapsedTime = clock.getElapsedTime();
	sf::Time oldTime;
	
	while(!done)
	{
		sf::Event event;
		while (wnd->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				done = true;
			}
		}
		//b->addToPosition(sf::Vector2f(0,0.1));
		elapsedTime = clock.getElapsedTime();
		wnd->clear();
		done = world.update(elapsedTime-oldTime);
		wnd->display();
		oldTime = elapsedTime;
	}
	wnd->close();
		
	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		
		window.clear();
		window.draw(shape);
		window.display();
	}
	*/

	return 0;
}