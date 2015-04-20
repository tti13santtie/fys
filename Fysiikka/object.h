#pragma once
#include "SFML\Graphics.hpp"
namespace fys
{
	class object
	{
		friend class world;
	public:
		object() :position(0, 0), acceleration(0, 0), force(0, 0){};
		virtual void update(sf::RenderWindow * wnd) = 0;
		~object(){};
		void setPosition(sf::Vector2f pos){ position = pos; }

	protected:
		sf::Vector2f force;
		sf::Vector2f position;
		sf::Vector2f acceleration;
	};
	
	class ball:public object
	{
	public:
		ball(float size) :size(size)
		{
			shape = sf::CircleShape(size);
			shape.setPosition(position);
		};
		~ball(){};
		void update(sf::RenderWindow * wnd)
		{
			wnd->draw(shape);
			return;
		}
	private:
		int size;
		sf::CircleShape shape;
	};
	class rectangle:public object
	{
	public:
		rectangle(sf::Vector2f size) :size(size)
		{
			shape = sf::RectangleShape(size);
			shape.setPosition(position);
		};
		~rectangle(){};
		void update(sf::RenderWindow * wnd)
		{
			wnd->draw(shape);
			return;
		}

	private:
		sf::Vector2f size;
		sf::RectangleShape shape;
	};
	
}