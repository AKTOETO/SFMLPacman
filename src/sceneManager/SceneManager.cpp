#include <iostream>

#include "SceneManager.h"

Engine::SceneManager::SceneManager() : currentSceneId(SCENES::MAIN_MENU)
{
	/*std::cout << "Scene manager\n";*/
	//TODO:
	// �������� ��� �����
	//scenesMap[SCENES::MAIN_MENU] = std::make_shared<BaseScene>(MainScene());// ����� ������ C2259	"Engine::BaseScene": ���������� ������� ��������� ������������ ������	

	//scenesMap[SCENES::MAIN_MENU]->activate();
}

/*bool Engine::SceneManager::setScene(SCENES scenesList, std::shared_ptr<Context>& context)
{
	scenesMap[SCENES::MAIN_MENU] = std::make_shared<MainScene>(context);
	try
	{
		currentScene = std::move(scenesMap[scenesList]);
		scenesMap[scenesList]->activate();
		return true;
	}
	catch (const char& e)
	{
		std::cerr << e << std::endl;
		//std::cerr << "�he scene named" <<  (static_cast<int>(scenesList) == 0? "MAIN_MENU":"") <<"was not activated" << std::endl;
		return 0;
	}
}*/

/*std::unique_ptr<Engine::BaseScene> Engine::SceneManager::getScene()
{
	return currentScene;
}*/
