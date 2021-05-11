#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Engine
{
	class BaseObject
	{
	public:
		BaseObject() {};
		~BaseObject() {};

		virtual void activate() = 0;

		virtual void processInput(sf::Event) = 0;
		virtual bool processUpdate(float time) = 0;
		virtual void processDraw() = 0;
	};
}