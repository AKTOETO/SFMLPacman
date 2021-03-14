#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "../Context.h"
#include "BaseObject.h"

namespace Engine
{
	class ButtonObject : public BaseObject
	{
	private:
		std::shared_ptr<Context> context;
	public:
		ButtonObject(std::shared_ptr<Context> context);
		~ButtonObject() { std::cout << "buttonObject destructor\n"; }

		void processInput() override;
		void processUpdate() override;
		void processDraw() override;
	};

}


