/**
 * @file SceneManager.cpp
 * @brief シーン管理クラス
 */

#include <cassert>

#include "SceneManager.h"
#include "SceneObjects.h"

 // シーンのインクルード
#include "SceneIntegrate.h"


SceneManager::SceneManager(SceneObjects* objects) {
	_objects = objects;
}
SceneManager::~SceneManager() {

}

void SceneManager::Initialize()
{
	_scene.emplace(_factory->CleateScene("TITLE"));
	//_objects->SetingLevel(_objects->levels.at(_objects->levelName_[0]).get());
}

void SceneManager::SceneInitialize() {
	_scene.top().get()->Initialize();
}

void SceneManager::SceneUpdate() {
	_scene.top().get()->Update();
}

void SceneManager::SceneDraw() {
	_scene.top().get()->Draw();
}

void SceneManager::ChangeScene() {

	if (goToTitle == true) {
		_scene.pop();
		_scene.pop();
		_scene.emplace(_factory->CleateScene("TITLE"));
		//_objects->SetingLevel(_objects->levels.at(_objects->levelName_[LEVELS::LV_TITLE]).get());
		SceneInitialize();
		//_objects->OFFIsUIDraw();
		//TransScene();
		goToTitle = false;
	}

	if (isChange == true && goToTitle == false) {

		switch (sceneNum)
		{
		case SCE_TITLE:
			_scene.pop();
			_scene.emplace(_factory->CleateScene("TITLE"));
			//_objects->OFFIsUIDraw();
			SceneInitialize();
			//TransScene();
			break;
		case SCE_GAME1:
		case SCE_GAME2:
		case SCE_GAME3:
			_scene.pop();
			_scene.emplace(_factory->CleateScene("GAME"));
			//_objects->ONIsUIDraw();
			SceneInitialize();
			//TransScene();
			break;
		case SCE_SELECT:
			_scene.pop();
			_scene.emplace(_factory->CleateScene("SELECT"));
			//_objects->OFFIsUIDraw();
			SceneInitialize();
			//TransScene();
			break;
		case SCE_CLEAR:
			_scene.pop();
			_scene.emplace(_factory->CleateScene("CLEAR"));
			//_objects->OFFIsUIDraw();
			SceneInitialize();
			//TransScene();
			break;
		case SCE_PAUSE:
			Pause();
			break;
			/////////////////////////////////////////////////////
		default:
			break;
		}
		isChange = false;
	}
	else {
		isChange = false;
	}
}

void SceneManager::TransScene()
{
	_scene.emplace(_factory->CleateScene("TRANS"));
	SceneInitialize();
}

void SceneManager::Pause()
{
	_scene.emplace(_factory->CleateScene("PAUSE"));
	SceneInitialize();
}

void SceneManager::PushScene(IScene* scene) {
	_scene.emplace(scene);
}
void SceneManager::PopScene() {
	_scene.pop();
	assert(!_scene.empty());
}