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

		virtual void processInput(sf::Event) = 0;
		virtual void processUpdate() = 0;
		virtual void processDraw() = 0;
	};
}