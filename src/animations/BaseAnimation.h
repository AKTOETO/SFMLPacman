#pragma once
#include <string>
#include <SFML/System/Time.hpp>

namespace Engine
{
	class BaseAnimation
	{
	protected:
		bool isPlay = false;

	public:
		BaseAnimation() {};
		~BaseAnimation() {};

		virtual void play() = 0;
		virtual void pause() = 0;

		virtual bool processUpdate(float time) = 0;
		virtual void processDraw() = 0;
	};
}



