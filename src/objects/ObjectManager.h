#pragma once
#include <map>
#include <memory>
#include <iostream>
#include "BaseObject.h"

namespace Engine
{
	enum class OBJECTS
	{
		MAIN_BUTTON = 0,
	};

	class ObjectManager
	{
	protected:
		std::map<OBJECTS, std::shared_ptr<BaseObject>> objects;

	public:
		ObjectManager();
		~ObjectManager();

		bool addObject(OBJECTS name, std::shared_ptr<BaseObject> object);
		std::shared_ptr<BaseObject> getObject(OBJECTS object);
	};
}


