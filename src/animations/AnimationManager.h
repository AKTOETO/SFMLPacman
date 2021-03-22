#pragma once
#include <map>
#include <memory>
#include <iostream>
#include "BaseAnimation.h"

namespace Engine
{
	enum class ANIMATION
	{
		SWITCH_SCENE = 0,
		R_SWITCH_SCENE = 0,
	};

	class AnimationManager
	{
	protected:
		std::map<ANIMATION, std::shared_ptr<BaseAnimation>> animations;

	public:
		AnimationManager() {};
		~AnimationManager() {};

		bool addAnimation(ANIMATION animationId, std::shared_ptr<BaseAnimation> animationClass);
		std::shared_ptr<BaseAnimation> getAnimation(ANIMATION animationId);
	};
}

