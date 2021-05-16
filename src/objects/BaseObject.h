#pragma once
#include "../Constans.h"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Engine
{
	class BaseObject
	{
	protected:
		float x, y;

	public:
		BaseObject() {};
		~BaseObject() {};

		virtual void activate() = 0;
		virtual void setPosition(float _x, float _y) { x = _x; y = _y; }
		virtual sf::Vector2f getPosition() { return sf::Vector2f(x, y); }

		virtual void processInput(sf::Event) = 0;
		virtual bool processUpdate(float time) = 0;
		virtual void processDraw() = 0;
	};
}