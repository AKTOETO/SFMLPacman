#pragma once
#include "../Context.h"
#include <memory>
#include "BaseAnimation.h"

namespace Engine
{
	class SwitchAnimation : public BaseAnimation
	{
	private:
		std::shared_ptr<Context> context;

		float curAngle, countSteps;
		int direction;

	public:
		SwitchAnimation(std::shared_ptr<Context>& _context);
		~SwitchAnimation() {};

		void play() override;
		void pause() override;

		bool processUpdate(float time) override;
		void processDraw() override;

	};
}

