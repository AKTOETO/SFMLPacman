#pragma once
#include <map>
#include <memory>
#include <iostream>
#include "BaseObject.h"
#include "../Constans.h"

namespace Engine
{
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


