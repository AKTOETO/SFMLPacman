#include "AnimationManager.h"

bool Engine::AnimationManager::addAnimation(ANIMATION animationId, std::shared_ptr<Engine::BaseAnimation> animationClass)
{
	animations[animationId] = move(animationClass);
	return true;
}

std::shared_ptr<Engine::BaseAnimation> Engine::AnimationManager::getAnimation(ANIMATION animationId)
{
	return animations[animationId];
}
