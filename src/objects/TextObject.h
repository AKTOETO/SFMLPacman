#pragma once
#include "../Context.h"
#include "BaseObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"


namespace Engine
{

	class TextObject : public BaseObject
	{
	private:
		std::shared_ptr<Context> context;
		sf::Text playText;

	public:
		TextObject() {};
	};

}

