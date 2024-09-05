#include "SceneFactory.h"
#include "SceneIntegrate.h"

IScene* SceneFactory::CleateScene(const std::string& sceneName)
{
	IScene* newScene = nullptr;

	if (sceneName == "TITLE") {
		newScene = new TitleScene();
	}
	if (sceneName == "CLEAR") {
		newScene = new Clear();
	}
	if (sceneName == "PAUSE") {
		newScene = new PauseScene();
	}
	if (sceneName == "SELECT") {
		newScene = new SelectScene();
	}
	if (sceneName == "TRANS") {
		newScene = new TransitionsScene();
	}
	if (sceneName == "GAME") {
		newScene = new MainGameScene();
	}

	return newScene;
}
