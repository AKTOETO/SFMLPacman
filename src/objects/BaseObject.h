#pragma once
#include <iostream>

namespace Engine
{
	class BaseObject
	{
	public:
		BaseObject() {};
		~BaseObject() {};

		virtual void processInput() = 0;
		virtual void processUpdate() = 0;
		virtual void processDraw() = 0;
	};
}