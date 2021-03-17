#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// Game engine
/// </summary>
namespace Engine
{
	class BaseScene
	{
	public:
		BaseScene() {};
		~BaseScene() {};

		virtual void activate() = 0;

		virtual void processInput(sf::Event) = 0;
		virtual void processUpdate() = 0;
		virtual void processDraw() = 0;
	};

}


