#include "MainScene.h"
#include <iostream>

void Engine::MainScene::activate()
{ 
	std::cout << "e" << std::endl;
}

void Engine::MainScene::processInput()
{
	std::cout << "e1" << std::endl;
}

void Engine::MainScene::processUpdate()
{
	std::cout << "e2" << std::endl;
}

void Engine::MainScene::processDraw()
{
	std::cout << "e3" << std::endl;
}
