#pragma once
#include <SFML\Graphics.hpp>
#include "object.h"
namespace fys
{
	class world
	{
	public:
		world(sf::RenderWindow * wnd):window(wnd){};
		~world(){};
		bool update(sf::Time elapsed)
		{
			for (std::vector<object*>::iterator it = objects.begin(); it != objects.end(); it++)
			{
				(*it)->update(window, elapsed);
			}
			return false;
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