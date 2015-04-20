#pragma once
#include <SFML\Graphics.hpp>
#include "object.h"
namespace fys
{
	class world
	{
	public:
		world()
		{
			window = new sf::RenderWindow(sf::VideoMode(200, 200), "Fysiikkaa");

		};
		~world(){};
		bool update()
		{
			window->clear();
			for (std::vector<object*>::iterator it = objects.begin(); it != objects.end(); it++)
			{
				(*it)->update(window);
			}
			window->display();
			return true;
		};
		void addObject(object * obj)
		{
			objects.push_back(obj);
		}
	private:
		sf::RenderWindow * window;
		float g;
		int floor;
		std::vector <object*> objects;

	};
}