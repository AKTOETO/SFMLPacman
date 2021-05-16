#pragma once
#include "../Context.h"
#include "../Constans.h"
#include "BaseObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"


namespace Engine
{

	class TextObject : public BaseObject
	{
	private:
		std::shared_ptr<Context> context;
		sf::Text text;

	public:
		TextObject(std::shared_ptr<Context> context, TextStyle t_style);
		~TextObject() {};

		void activate() override;

		void processInput(sf::Event) override;
		bool processUpdate(float time) override;
		void processDraw() override;
	};

}

