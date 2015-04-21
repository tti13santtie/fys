#pragma once
#include "SFML\Graphics.hpp"


namespace fys
{
	const float g = 9.81;
	const float distDivider = 100;
	class object
	{
		friend class world;
	public:
		object() :position(0, 0), acceleration(0, 0), force(0, 0), gravity(true){};
		virtual void update(sf::RenderWindow * wnd, sf::Time elapsed) = 0;
		~object(){};
		void setPosition(sf::Vector2f pos){ position = pos; }
		void addToPosition(sf::Vector2f pos)
		{
			position = position + pos;
		}
		void setGravity(bool toSet){gravity = toSet;}
	protected:
		void updateBase(sf::Time delta, sf::Vector2u size)
		{
			shape->setPosition(position);
			if(gravity == false)
				return;
			acceleration += sf::Vector2f(0,(g/distDivider)*delta.asSeconds());
			addToPosition(acceleration);
			if(position.y > size.y)
			{
				acceleration.y = -acceleration.y;
				//setPosition(sf::Vector2f(position.x,0));
			}
			shape->setPosition(position);
		}
		float friction;
		float mass;
		bool gravity;
		sf::Shape * shape;
		sf::Vector2f force;
		sf::Vector2f position;
		sf::Vector2f acceleration;
	};
	
	class ball:public object
	{
	public:
		ball(float size) :size(size)
		{
			shape = new sf::CircleShape(size);
			shape->setPosition(position);
			shape->setFillColor(sf::Color::Green);
		};
		~ball(){};
		void update(sf::RenderWindow * wnd, sf::Time elapsed)
		{
			//Check for collisions first
			updateBase(elapsed,wnd->getSize());
			wnd->draw(*shape);
			return;
		}
	private:
		int size;
	};
	class rectangle:public object
	{
	public:
		rectangle(sf::Vector2f size) :size(size)
		{
			shape = new sf::RectangleShape(size);
			shape->setPosition(position);
		};
		~rectangle(){};
		void update(sf::RenderWindow * wnd, sf::Time elapsed)
		{
			updateBase(elapsed,wnd->getSize());
			wnd->draw(*shape);
			return;
		}

	private:
		sf::Vector2f size;
	};
	
}